#include <stdio.h>
#include <unistd.h>
#include "../../src/string_manipulation.h"
#include "../include/munit.h"
#define CONCAT_TEST_VALUES_COUNT 4

typedef struct {
    int count;
    char **words;
    char *concatenated;
} ConcatTestStruct;

static char *completeWordSet[2] = { (char *)"word1", (char *)"word2" };
static char *oneEmptyWordSet[2] = { (char *)"", (char *)"word2" };
static char *twoEmptyWordSet[2] = { (char *)"", (char *)"" };

ConcatTestStruct concatTestValues[CONCAT_TEST_VALUES_COUNT] = {
    { 2, completeWordSet, (char *) "word1word2" },  // Normal case
    { 2, oneEmptyWordSet, (char *) "word2" },       // Edge case (empty string in the list)
    { 2, twoEmptyWordSet, (char *) "" },            // Edge case (only empty strings)
    { 1, completeWordSet, (char *) "word1" },       // Edge case (more arguments than specified)
    // { 3, completeWordSet, NULL },                // Error case (less arguments than specified) => Cannot be caught; therefore it will always crash
    // {-1, completeWordSet, (char *)"" }           // Error case (negative argument count) => Variadic function; this will always cause a segmentation fault
};

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
static MunitResult test_concat(const MunitParameter params[], void *data) {
    // Silencing the compiler
    (void) data;
    (void) params;
    
    for (int i = 0; i < CONCAT_TEST_VALUES_COUNT; i++) {
        char *expected = concatTestValues[i].concatenated;
        char *obtained = concat(concatTestValues[i].count, concatTestValues[i].words[0], concatTestValues[i].words[1]);

        munit_assert_string_equal(obtained, expected);
    }

    // Static test: edge case with 0 args
    char *expected = "";
    char *obtained = concat(0);
    munit_assert_string_equal(obtained, expected);

    return MUNIT_OK;
}
#pragma GCC diagnostic pop
