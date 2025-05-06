// Import math_library.h
#include "math_library.h"

const int returnOfFalse = -1;

/*
 * FUNCTION:
 *    add
 * DESCRIPTION:
 *    Returns the sum of two integers.
 * PARAMETERS:
 *    int a: integer for doing operation
 *    int b: integer for doing operation
 * RETURNS:
 *    int a + b: the sum of two integers.
 */
int add(int a, int b) {
	return a + b;
}

/*
 * FUNCTION:
 *    subtract
 * DESCRIPTION:
 *    Returns the result of subtracting two integers.
 * PARAMETERS:
 *    int a: integer for doing operation
 *    int b: integer for doing operation
 * RETURNS:
 *    int a - b: the result of substracting two integers.
 */
int subtract(int a, int b) {
	return a - b;
}

/*
 * FUNCTION:
 *    divide
 * DESCRIPTION:
 *    Returns the result of dividing two integers.
 * PARAMETERS:
 *    int a: integer for doing operation
 *    int b: integer for doing operation
 * RETURNS:
 *    int a / b: the result of dividing two integers.
 */
int divide(int a, int b) {
	// Using if statement to check if variable b is 0 or not
	if (b == 0) {
		// Print the error message if variable b is 0
		printf("Error: Divsion by 0 is not allowed.\n");
		return returnOfFalse;
	}
	else
	{
		return a / b;
	}
}


/*
 * FUNCTION:
 *    multiply
 * DESCRIPTION:
 *    Returns the result of multiplying two integers.
 * PARAMETERS:
 *    int a: integer for doing operation
 *    int b: integer for doing operation
 * RETURNS:
 *    int a * b: the result of multiplying two integers.
 */
int multiply(int a, int b) {
	return a * b;
}