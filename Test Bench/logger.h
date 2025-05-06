#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
// Import time.h for using time_t
#include <time.h>  // Reference: https://www.tutorialspoint.com/c_standard_library/time_h.htm

// Prototype of initLogger
void initLogger(const char* filename);
// Prototype of logMessage
void logMessage(const char* level, const char* message);
// Prototype of closeLogger
void closeLogger();

#endif
