#pragma once
/**
 * Library containing the time functions of the framework.
 */

#include <unistd.h>
#include <string.h>
#include <time.h>

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
extern char *getTime();
