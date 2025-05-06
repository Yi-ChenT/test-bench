// Import standard library for exit()
#include <stdlib.h>
// Import logger.h
#include "logger.h"

// Declare a file pointer for the log file and make it static which is only visible in this file
static FILE* logFile = NULL;

// Declare a variable to store maximum length for the time string buffer
#define MAX_LENGTH_OF_TIME_STRING 50

/*
* FUNCTION:
*    initLogger
* DESCRIPTION:
*    Initializes the logger by opening the specified log file in append mode.
* PARAMETERS:
*    const char* filename: The name of the log file to open.
* RETURNS:
*    No return.
*/
void initLogger(const char* filename) {
    // Using if statement to check if a log file is already open or not
    if (logFile != NULL) {
        fclose(logFile);
    }
    // Open the log file in append mode ("a")
    errno_t err = fopen_s(&logFile, filename, "a");
    // Using if statement to check if opening fails or not
    if (err != 0) {
        // Using fprintf to print the error message
        fprintf(stderr, "Error: Could not open log file %s\n", filename);
        exit(EXIT_FAILURE);
    }
}

/*
* FUNCTION:
*    logMessage
* DESCRIPTION:
*    Writes a log message to the log file with the current timestamp and log level.
* PARAMETERS:
*    const char* level   : The log level (e.g., "INFO").
*    const char* message : The formatted log message.
* RETURNS:
*    No return.
*/
void logMessage(const char* level, const char* message) {
    // Using if statement to check if the logger has been initialized
    if (logFile == NULL) {
        // Using fprintf to print the error message
        fprintf(stderr, "Logger is not initialized.\n");
        return;
    }

    // Get the current time as a time_t object
    time_t currentTime = time(NULL);  // Reference: https://www.tutorialspoint.com/c_standard_library/c_function_time.htm
    // Convert the time_t value to a local time representation (struct tm)
    struct tm* timeStruct = localtime(&currentTime);
    // Declare a buffer to hold the formatted time string
    char timeString[MAX_LENGTH_OF_TIME_STRING];
    // Format the time into a string in the format "YYYY-MM-DD HH:MM:SS"
    strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", timeStruct);  // Reference: https://www.tutorialspoint.com/c_standard_library/c_function_strftime.htm

    // Write the log message to the file in the format
    fprintf(logFile, "[%s] [%s] %s\n", timeString, level, message);
    // Using fflush to flush the log file to ensure that the message is immediately written to disk
    fflush(logFile);
}

/*
* FUNCTION:
*    closeLogger
* DESCRIPTION:
*    Closes the currently opened log file and resets the log file pointer.
* PARAMETERS:
*    None.
* RETURNS:
*    No return.
*/
void closeLogger() {
    // Using if statement to check if the log file is open or not
    if (logFile != NULL) {
        // Close log file
        fclose(logFile);
        // Set the log file to NULL
        logFile = NULL;
    }
}
