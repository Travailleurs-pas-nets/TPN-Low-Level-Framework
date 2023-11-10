/**
 * Library containing the logging functions of the framework.
 */

#include <stdio.h>
#include "ll_constants.h"
#include "string_manipulation.h"

/**
 * Function that flushes the console output in debug mode.
 * 
 * See logger modes for the last parameter (1 = DEBUG, 0 = PROD).
 * 
 * TODO: Add examples.
 */
extern void flushOutput(int mode);

/**
 * Function that handles errors.
 * If the debug mode is enabled, these will be displayed in the terminal, otherwise they will be
 * written to a log file.
 * 
 * See logger modes for the last parameter (1 = DEBUG, 0 = PROD).
 * 
 * TODO: Add examples.
 */
extern void handleError(char *errorTag, char *message, char *charTime, int mode);

/**
 * Function that handles runtime errors.
 * These errors takes the `[ERROR]` tag.
 * 
 * See logger modes for the last parameter (1 = DEBUG, 0 = PROD).
 * 
 * TODO: Add examples.
 */
extern void handleRuntimeError(char *message, char *charTime, int mode);

/**
 * Function that handles critical errors.
 * These errors takes the `[CRITICAL]` tag and causes the program to stop.
 * 
 * See logger modes for the last parameter (1 = DEBUG, 0 = PROD).
 * 
 * TODO: Add examples.
 */
extern void handleCriticalError(char *message, char *charTime, int mode);

/**
 * Function that handles standard debug display.
 * If the debug mode is enabled, it will display the informations in the terminal, otherwise it
 * won't display anything.
 * 
 * See logger modes for the last parameter (1 = DEBUG, 0 = PROD).
 * 
 * TODO: Add examples.
 */
extern void debug(const char *messageTemplate, char *charTime, char *content, int mode);
