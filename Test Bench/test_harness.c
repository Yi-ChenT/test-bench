#include <stdio.h>
// Import boolean operation
#include <stdbool.h>
// Import limits for using max and min integer range
#include <limits.h>
// Import test_harness.h
#include "test_harness.h"
// Import math_library.h
#include "math_library.h"
// Import logger.h
#include "logger.h"


// Declare a constant to store the maximum length for the formatted message buffer
#define MAX_LENGTH_OF_MESSAGE_BUFFER 150

// Create a structure for a single test case
typedef struct {
    // Test case name or description
    const char* testName;     
    // Function pointer for the math operation
    int (*mathOp)(int, int);
    // First input operand
    int firstInput;    
    // Second input operand
    int secondInput;    
    // Expected result for the test case
    int expectedResult;          
} testCase;


// Create an array of test cases
static testCase testCases[] = {
    {"Positive Test(Add): 3 + 4", add, 3, 4, 7},
    {"Positive Test(Subtract): 5 - (-5)", subtract, 5, -5, 10},
    {"Positive Test(divide): 10 - 5", subtract, 10, 5, 5},
    {"Positive Test(multiply): (-2) * 6", multiply, -2, 6, -12},
    {"Negative Test(multiply): 9868637 * 20", multiply, 9868637, 20, 197372740},
    {"Negative Test(division by 0): 10 / 0", divide, 10, 0, 0},
    {"Bondary Test(divide): 2 ^ 31 - 1(Max value of integer) / 1", divide, INT_MAX, 1, INT_MAX},
    {"Bondary Test(multiply): -2 ^ 31(Min value of integer) * 1", multiply, INT_MIN, 1, INT_MIN}
};

// Calculate the number of test cases in the testCases array
static int numberOfTests = sizeof(testCases) / sizeof(testCase);

/*
* FUNCTION:
*    runTest
* DESCRIPTION:
*    Executes a single test case by calling the specified math operation, comparing the result with the expected value, logging the result
* PARAMETERS:
*    testCase testCase: A structure containing the test case information.
* RETURNS:
*    No return.
*/
static void runTest(testCase testCase) {
    // Call the math operation function with provided inputs
    int result = testCase.mathOp(testCase.firstInput, testCase.secondInput);

    // Determine if the test passed by comparing the result to the expected value
    int pass = (result == testCase.expectedResult);

    // Declare a variable to store a buffer to hold the formatted log message
    char messageBuffer[MAX_LENGTH_OF_MESSAGE_BUFFER];

    // Format the test result into the message buffer
    snprintf(messageBuffer, sizeof(messageBuffer),
        "\nTest: %s, Inputs: (%d, %d), Expected: %d, Result: %d, %s",
        testCase.testName, testCase.firstInput, testCase.secondInput, testCase.expectedResult, result,
        pass ? "\nPASSED" : "\nFAILED");

    // Log the formatted test result message with INFO level
    logMessage("INFO", messageBuffer);

    // Print the word to the screen
    printf("%s: %s ||Expected: %d, Result: %d||\n",
        testCase.testName, pass ? "\nPASSED" : "\nFAILED", testCase.expectedResult, result);
}

/*
* FUNCTION:
*    runAllTests
* DESCRIPTION:
*    Iterates through all defined test cases and executes each test.
* PARAMETERS:
*    None.
* RETURNS:
*    No return.
*/
void runAllTests() {
    // Loop through each test case in the testCases array
    for (int i = 0; i < numberOfTests; i++) {
        // Execute the current test case
        runTest(testCases[i]);  
    }
}

/*
* FUNCTION:
*    runIndividualTest
* DESCRIPTION:
*    Displays a list of available test cases, prompts the user to select one, and then executes the selected test case.
* PARAMETERS:
*    None.
* RETURNS:
*    No return.
*/
void runIndividualTest() {
    // Print the word to the screen
    printf("Test Cases:\n");

    // Using for loop to traverse each test case to display its number and name
    for (int i = 0; i < numberOfTests; i++) {
        printf("%d: %s\n", i + 1, testCases[i].testName);
    }

    // Print the word to the screen
    printf("Enter test case number: ");

    // Declare a variable to store the user's selection
    int option;

    // Using if statement to check if the user's input is valid or not
    if (scanf_s("%d", &option) != 1) {
        printf("Invalid input.\n");
        return;
    }

    // Using if statement to check if the entered option is within the valid range
    if (option < 1 || option > numberOfTests) {
        printf("Invalid test case number.\n");
        return;
    }

    // Execute the selected test case
    runTest(testCases[option - 1]);
}
