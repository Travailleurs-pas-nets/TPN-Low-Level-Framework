/**
 * Library containing the time functions of the framework.
 */

#include "chron.h"

/**
 * Function that returns the current time (when calling the method) as a char array.
 * 
 * ⚠️ WARNING: This function contains a hidden `malloc`, therefore, when you are done with the
 * value, you should free its memory.
 * 
 * Example:
 * ```c
 * char *time_string = getTime();
 * free(time_string);
 * ```
 */
char *getTime() {
    time_t rawTime = time(NULL);
    char *charTime = ctime(&rawTime);
    charTime[strlen(charTime) - 1] = '\0'; /* Removing the line break at the end. */

    return charTime;
}
