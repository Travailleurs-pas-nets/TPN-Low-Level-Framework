/**
 * Library containing the logging functions of the framework.
 */

#include "logger.h"

/**
 * Function that flushes the console output in debug mode.
 * 
 * See logger modes for the last parameter (1 = DEBUG, 0 = PROD).
 * 
 * TODO: Add examples.
 */
void flushOutput(int mode) {
    if (mode == LL_DEBUG) {
        printf("\n");
    }
}

/**
 * Function that handles errors.
 * If the debug mode is enabled, these will be displayed in the terminal, otherwise they will be
 * written to a log file.
 * 
 * See logger modes for the last parameter (1 = DEBUG, 0 = PROD).
 * 
 * TODO: Add examples.
 */
void handleError(char *errorTag, char *message, char *charTime, int mode) {
    char *errorMessage = concat(5, errorTag, " ", charTime, ": ", message);

    if (mode == LL_DEBUG) {
        perror(errorMessage);
    } else {
        // TODO (writing in a log file)
    }

    //free(errorMessage);
}

/**
 * Function that handles runtime errors.
 * These errors takes the `[ERROR]` tag.
 * 
 * See logger modes for the last parameter (1 = DEBUG, 0 = PROD).
 * 
 * TODO: Add examples.
 */
void handleRuntimeError(char *message, char *charTime, int mode) {
    handleError("[ERROR]", message, charTime, mode);
}

/**
 * Function that handles critical errors.
 * These errors takes the `[CRITICAL]` tag and causes the program to stop.
 * 
 * See logger modes for the last parameter (1 = DEBUG, 0 = PROD).
 * 
 * TODO: Add examples.
 */
void handleCriticalError(char *message, char *charTime, int mode) {
    handleError("[CRITICAL]", message, charTime, mode);
    //exit(1); // Has to be commented when testing!
}

/**
 * Function that handles standard debug display.
 * If the debug mode is enabled, it will display the informations in the terminal, otherwise it
 * won't display anything.
 * 
 * See logger modes for the last parameter (1 = DEBUG, 0 = PROD).
 * 
 * TODO: Add examples.
 */
void debug(const char *messageTemplate, char *charTime, char *content, int mode) {
    if (mode == LL_DEBUG) {
        printf(messageTemplate, charTime, content);
    }
}
