/**
 * Library containing the string manipulation functions of the framework.
 */

#include "string_manipulation.h"

/**
 * Function that converts an integer in a char array.
 * 
 * TODO: Add examples.
 */
char *intToChars(int in) {
    char *result;
    int nextIndex = 0;
    bool startedWriting = false;

    if (in >= 0) {
        int size = 10; /* Max length of a 32 bits int. */
        result = malloc(size);
    } else {
        int size = 11; /* +1 for the minus sign. */
        result = malloc(size);
        result[nextIndex] = '-';
        nextIndex++;
    }

    for (int power = 9; power >= 0; power--) {
        int value = (int) floor(in / pow(10, power));

        /* second condition because we don't want to stop writing the string once we started,
           otherwise we will lose powers of ten in the resulting array of characters. */
        if (value >= 1 || startedWriting) {
            result[nextIndex] = value + 48;
            nextIndex++;

            in -= value * (int)pow(10, power);
            startedWriting = true;
        }
    }

    result[nextIndex] = '\0';
    return result;
}

/**
 * Function that concatenates the given amount parameters.
 * 
 * TODO: Add examples.
 */
char *concat(unsigned short argCount, ...) {
    va_list argList;
    char *concatenated;
    int size = 1;
    
    va_start(argList, argCount);
    for (int i = 0; i < argCount; i++) {
        size += strlen(va_arg(argList, char *));
    }
    va_end(argList);
    
    concatenated = malloc(size + 1);
    *concatenated = '\0';

    va_start(argList, argCount);
    for (int i = 0; i < argCount; i++) {
        strcat(concatenated, va_arg(argList, char *));
    }
    va_end(argList);

    return concatenated;
}


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-value"
/**
 * Function that splits a string into an array of strings, using the given delimiter.
 * 
 * The pragmas are because we use values pointed to, which will trigger a warning at compile time,
 * saying a computed value is not used, while it actually is.
 * 
 * TODO: Add examples.
 */
char **split(char *stringToSplit, char delimiter, unsigned short *wordCount) {
    char *token;
    char **tokens;
    char delimiterAsString[1] = { delimiter };
    unsigned short delimiterCount = 0;
    unsigned short localWordCount = 0;
    char *stringDuplicate = strdup(stringToSplit); // Copying the string to ensure it stays unchanged.

    // First, we iterate through the string to find the number of times the delimiter is present.
    for (int i = 0; stringDuplicate[i] != '\0'; i++) {
        if (stringDuplicate[i] == delimiter) {
            delimiterCount++;
        }
    }

    // Then we create an array of a capacity of 1 more than the delimiter count (because there is
    // one more element than there are delimiters).
    tokens = malloc(sizeof(char *) * (delimiterCount + 2));

    // And finally we fill our array with strings.
    token = strtok(stringDuplicate, delimiterAsString);
    while (token) {
        tokens[localWordCount] = token;
        localWordCount++;
        token = strtok(NULL, delimiterAsString);
    }
    
    *wordCount = localWordCount;
    tokens[localWordCount + 1] = 0;
    return tokens;
}
#pragma GCC diagnostic pop

/**
 * Function that creates a string of the given length, filled with question marks.
 * 
 * TODO: Add examples.
 */
char *createQuestionMarkString(int length) {
    char *word = malloc(length);

    for (int i = 0; i < length - 1; i++) {
        word[i] = '?';
    }

    word[length - 1] = '\0';
    return word;
}
