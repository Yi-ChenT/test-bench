#include <stdio.h>
// Import standard library for exit()
#include <stdlib.h>
// Import boolean operation
#include <stdbool.h>
// Import logger.h
#include "logger.h"
// Import test_harness.h
#include "test_harness.h"

// Declare a constant variable for the max length of filename
#define MAX_LENGTH_OF_FILENAME 50
// Declare a constant variable for the successful running the program and exiting the program
#define SUCCESS 0

// Define an enum for the menu options
typedef enum {
    menuOfRunIndividualTest = 1,
    menuOfRunAllTest,
    menuOfViewLogs,
    menuOfExit
} menuOption;

// Prototype of displayMenu
void displayMenu();
// Prototype of viewLogs
void viewLogs();
// Prototype of clearTestLog
void clearTestLog();
// Prototype of clearInput
void clearInput();


int main(void) {

    // Declare a variable to store user's menu choice
    int option; 
    
    initLogger("program.log");
    // Call the logMessage and write a log message for initialization
    logMessage("INFO", "Program started.");

    // Keep displaying menu until user choose to exit
    while (true) {

        // Call the displayMenu function to display menu
        displayMenu();

        // Using if statement to check if the user input is an integer or not
        if (scanf_s("%d", &option) != 1) {
            // Display error message if the input is invalid
            printf("Invalid input. Please enter a number.\n");
            // Clear the input buffer
            clearInput();
            // Continue the loop
            continue;
        }
        // Using switch to process user's menu choice
        switch ((menuOption)option) {

        case menuOfRunIndividualTest:
            // Call the clearTestLog function
            clearTestLog();
            // Call the closeLogger function
            closeLogger();
            // Call the initLogger function to open logger with test.log
            initLogger("test.log");
            // Call the runIndividualTest function
            runIndividualTest();
            // Call the closeLogger function to close the logger
            closeLogger();
            // Call the initLogger function to reinitialize logger back to program.log
            initLogger("program.log");
            // Break out of the loop
            break;

        case menuOfRunAllTest:
            // Call the clearTestLog function
            clearTestLog();
            // Call the closeLogger function
            closeLogger();
            // Call the initLogger function to open logger with test.log
            initLogger("test.log");
            // Call the runAllTests function
            runAllTests();
            // Call the closeLogger function to close the logger
            closeLogger();
            // Call the initLogger function to reinitialize logger back to program.log
            initLogger("program.log");
            // Break out of the loop
            break;

        case menuOfViewLogs:
            // Call the viewLogs function to view the log file contents
            viewLogs();
            // Break out of the loop
            break;

        case menuOfExit:
            // Log the program exiting message
            logMessage("INFO", "Program exiting.");
            // Close logger and exit the program with success status
            closeLogger();
            // Exit the program successfully
            exit(EXIT_SUCCESS);
            // Break out of the loop
            break;

        default:
            // Print the error message to the screen if the user's input is invalid
            printf("Invalid choice. Please try again.\n");
            // Break out of the loop
            break;
        }
    }

    // Close logger if loop somehow terminates
    closeLogger();
    return SUCCESS;
}

/*
 * FUNCTION:
 *    displayMenu
 * DESCRIPTION:
 *    This function displays the main menu options to the user.
 * PARAMETERS:
 *    None
 * RETURNS:
 *    No return.
 */
void displayMenu() {
    // Print the word to the screen
    printf("\n-----Main Menu-----\n");
    // Print the word to the screen
    printf("1. Run Individual Test Case\n");
    // Print the word to the screen
    printf("2. Run All Test Cases\n");
    // Print the word to the screen
    printf("3. View Log Files\n");
    // Print the word to the screen
    printf("4. Exit\n");
    // Print the word to the screen
    printf("Enter your choice: ");
}

/*
 * FUNCTION:
 *    viewLogs
 * DESCRIPTION:
 *    This function allows the user to view the contents of a log file.
 * PARAMETERS:
 *    None
 * RETURNS:
 *    No return.
 */
void viewLogs() {
    
    // Close the logger
    closeLogger();

    // Declare a variable to store the user's log file choice
    int choice; 

    // Print the word to the screen
    printf("\nSelect Log File to View:\n");
    printf("1. program.log\n");
    printf("2. test.log\n");
    printf("Enter your choice: ");

    // Using if statement to check if the user's input is an integer or not
    if (scanf_s("%d", &choice) != 1) {
        // Display error message if user's input is invalid
        printf("Invalid input. Please enter a number\n");
        return;
    }

    // Declare a variable to store the selected file name
    char fileName[MAX_LENGTH_OF_FILENAME]; 

    // Using if statement to check if the file name based on user's choice
    if (choice == menuOfRunIndividualTest) {
        snprintf(fileName, sizeof(fileName), "program.log");
    }
    else if (choice == menuOfRunAllTest) {
        snprintf(fileName, sizeof(fileName), "test.log");
    }
    else {
        // Print the error message and return to the main menu if the user's input is invalid
        printf("Invalid choice.\n");
        return;
    }

    // Declare a file pointer to read the log file
    FILE* filePtr = NULL; 
    // Open the selected file in read mode
    errno_t err = fopen_s(&filePtr, fileName, "r");
    if (err != 0 || filePtr == NULL) {
        // Display the error message if the file can not be opened
        printf("Could not open %s\n", fileName);
        return;
    }

    // Print the word to the screen
    printf("\n------Contents of file------\n");

    // Declare a variable to store characters read from the file
    int text; 
    // Using while loop to read and display file content character by character until EOF is reached
    while ((text = fgetc(filePtr)) != EOF) {
        putchar(text);
    }
    // Print the word to the screen
    printf("\n------End of file------\n");
    // Close the file pointer
    fclose(filePtr);
}

/*
 * FUNCTION:
 *    clearTestLog
 * DESCRIPTION:
 *    This function clears the contents of the test.log file by opening it in write mode.
 * PARAMETERS:
 *    None
 * RETURNS:
 *    No return.
 */
void clearTestLog(void) {
    // Declare a file pointer for clearing test.log
    FILE* temp = NULL; 
    // Open test.log in write mode to clear its contents
    errno_t err = fopen_s(&temp, "test.log", "w");
    if (err != 0 || temp == NULL) {
        // Print the error message to the screen if the file cannot be opened
        printf("Error: Could not clear the test.log\n");
    }
    else {
        // Close the temporary file pointer after clearing
        fclose(temp);
    }
}

/*
 * FUNCTION:
 *    clearInput
 * DESCRIPTION:
 *    This function clears the input buffer by reading and discarding characters until a newline or EOF is encountered.
 * PARAMETERS:
 *    None
 * RETURNS:
 *    No return.
 */
void clearInput(void) {
    // Declare a variable to store characters from input
    int text;
    // Using while loop to read and discard characters until newline or EOF is reached
    while ((text = getchar()) != '\n' && text != EOF);
}
