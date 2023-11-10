/**
 * Library containing the time functions of the framework.
 */

#include "chron.h"

/**
 * Function that returns the current time (when calling the method) as a char array.
 * 
 * TODO: Add examples.
 */
char *getTime() {
    time_t rawTime = time(NULL);
    char *charTime = ctime(&rawTime);
    charTime[strlen(charTime) - 1] = '\0'; /* Removing the line break at the end. */

    return charTime;
}
