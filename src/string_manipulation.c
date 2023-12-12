/**
 * Library containing the string manipulation functions of the framework.
 */

#include "string_manipulation.h"

/**
 * Function that converts an integer in a char array.
 * 
 * ⚠️ WARNING: This function contains a hidden `malloc`, therefore, when you are done with the
 * value, you should free its memory.
 * 
 * Examples:
 * ```c
 * char *n = intToChars(1000);
 * char *k = intToChars(-1280);
 * 
 * printf("n = %s \\nk = %s", n, k);
 * free(n);
 * free(k);
 * ```
 * 
 * => output:
 * ```txt
 * n = 1000
 * k = -1280
 * ```
 */
char *intToChars(int in) {
    char *result;
    int nextIndex = 0;
    bool startedWriting = false;
    bool isMinValue = (in == INT_MIN);

    if (in >= 0) {
        int size = 10; /* Max length of a 32 bits int. */
        result = malloc(size);
    } else {
        int size = 11; /* +1 for the minus sign. */
        result = malloc(size);
        result[nextIndex] = '-';
        nextIndex++;

        if (isMinValue) {
            in += 1; // We'll add that back later...
        }

        in *= -1;
    }

    for (int power = 9; power >= 0; power--) {
        if (isMinValue && power == 0) {
            // Adding back the value that was deduced to make the inversion possible
            in += 1; // (+ because we work with the opposite).
        }

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

    if(!startedWriting) {
        result[nextIndex] = '0';
        nextIndex++;
    }

    result[nextIndex] = '\0';
    return result;
}

/**
 * Function that concatenates the given amount parameters.
 * 
 * ⚠️ WARNING: This function contains a hidden `malloc`, therefore, when you are done with the
 * value, you should free its memory.
 * 
 * Example:
 * ```c
 * char *concatenated = concat(3, "I am ", "a part of", " a string!");
 * 
 * print(concatenated);
 * free(concatenated);
 * ```
 * 
 * => output:
 * ```txt
 * I am a part of a string!
 * ```
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
 * ⚠️ WARNING: This function contains a hidden `malloc`, therefore, when you are done with the
 * values, you should free every individual one, and then the global pointer returned by this
 * function.
 * 
 * The pragmas are because we use values pointed to, which will trigger a warning at compile time,
 * saying a computed value is not used, while it actually is.
 * 
 * Example:
 * ```c
 * char *str_to_split = "I am a string to split";
 * unsigned short count;
 * 
 * char **splitted_string = split(str_to_split, ' ', &count);
 * ```
 * 
 * => values at the end:
 * ```txt
 * splitted_string : { "I", "am", "a", "string", "to", "split" }
 * count: 6
 * ```
 */
char **split(char *stringToSplit, char delimiter, unsigned short *wordCount) {
    char *token;
    char **tokens;
    char delimiterAsString[1] = { delimiter };
    unsigned short delimiterCount = 0;
    unsigned short localWordCount = 0;
    char *stringDuplicate = strdup(stringToSplit); // Copying the string to ensure it stays unchanged.
    bool lastCharDelimiter = false;

    // First, we iterate through the string to find the number of times the delimiter is present.
    for (int i = 0; stringDuplicate[i] != '\0'; i++) {
        bool isFirstChar = (i == 0);
        bool isLastChar = (i == strlen(stringDuplicate) - 1);

        if (stringDuplicate[i] == delimiter) {
            if (!lastCharDelimiter && !isFirstChar && !isLastChar) {
                delimiterCount++;
            }

            lastCharDelimiter = true;
        } else {
            lastCharDelimiter = false;
        }
    }

    // Then we create an array of a capacity of 1 more than the delimiter count (because there is
    // one more element than there are delimiters).
    tokens = malloc(sizeof(char *) * (delimiterCount + 2));

    // And finally we fill our array with strings.
    token = strtok(stringDuplicate, delimiterAsString);
    while (token) {
        tokens[localWordCount] = strdup(token);
        localWordCount++;
        token = strtok(NULL, delimiterAsString);
    }

    if (localWordCount == 0) {
        // Giving an array with only one empty string if there was nothing the tokenizer could find
        // in the given string.
        tokens[0] = "";
        localWordCount++;
    }

    free(stringDuplicate);
    
    *wordCount = localWordCount;
    tokens[localWordCount + 1] = 0;
    return tokens;
}
#pragma GCC diagnostic pop

/**
 * Function that creates a string of the given length, filled with question marks.
 * 
 * ⚠️ WARNING: This function contains a hidden `malloc`, therefore, when you are done with the
 * value, you should free its memory.
 * 
 * Example:
 * ```c
 * char *str = createQuestionMarkString(6);
 * printf("'%s'", str);
 * 
 * free(str);
 * ```
 * 
 * => output:
 * ```txt
 * '??????'
 * ```
 */
char *createQuestionMarkString(int length) {
    char *word = malloc(sizeof(char) * (length + 1));

    for (int i = 0; i < length; i++) {
        word[i] = '?';
    }

    word[length] = '\0';
    return word;
}

/**
 * Function that counts the number of letters in a word. By default, it stops when it encounters a
 * whitespace (' ').
 * 
 * Example:
 * ```c
 * char *str = "this is a test string";
 * char *other_pointer = str + 5;
 * 
 * unsigned int first_word_length = wrdlen(str);
 * unsigned int second_word_length = wrdlen(other_pointer);
 * 
 * printf("first word length = %d\n", first_word_length);
 * printf("second word length = %d\n", second_word_length);
 * ```
 * 
 * => output:
 * ```txt
 * first word length = 4
 * second word length = 2
 * ```
 */
unsigned int wrdlen(const char *sentence)
{
    unsigned int count = 0;
    while (*(sentence + count) != ' ' && *(sentence + count) != '\0') count++;
    return count;
}
