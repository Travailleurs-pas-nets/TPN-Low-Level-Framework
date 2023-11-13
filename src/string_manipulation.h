/**
 * Library containing the string manipulation functions of the framework.
 */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

/**
 * Function that converts an integer in a char array.
 * 
 * TODO: Add examples.
 */
extern char *intToChars(int in);

/**
 * Function that concatenates the given amount parameters.
 * 
 * TODO: Add examples.
 */
extern char *concat(unsigned short argCount, ...);

/**
 * Function that splits a string into an array of strings, using the given delimiter.
 * 
 * The pragmas are because we use values pointed to, which will trigger a warning at compile time,
 * saying a computed value is not used, while it actually is.
 * 
 * TODO: Add examples.
 */
extern char **split(char *stringToSplit, char delimiter, unsigned short *wordCount);

/**
 * Function that creates a string of the given length, filled with question marks.
 * 
 * TODO: Add examples.
 */
extern char *createQuestionMarkString(int length);
