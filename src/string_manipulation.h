#pragma once

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
extern char *intToChars(int in);

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
extern char *concat(unsigned short argCount, ...);

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
extern char **split(char *stringToSplit, char delimiter, unsigned short *wordCount);

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
extern char *createQuestionMarkString(int length);

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
extern unsigned int wrdlen(const char *sentence);
