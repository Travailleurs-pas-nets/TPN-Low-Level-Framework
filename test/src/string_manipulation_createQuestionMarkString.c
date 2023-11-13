#include <stdio.h>
#include <unistd.h>
#include "../../src/string_manipulation.h"
#include "../include/munit.h"
#define CREATE_QUESTION_MARK_STRING_TEST_VALUES_COUNT 2

typedef struct {
    int length;
    char *generatedString;
} CreateQuestionMarkStringTestStruct;

CreateQuestionMarkStringTestStruct createQuestionMarkStringTestValues[CREATE_QUESTION_MARK_STRING_TEST_VALUES_COUNT] = {
    { 3, (char *)"???" },   // Normal case, n length
    { 0, (char *)"" },      // Edge case, 0 length
    // {-1, NULL },         // Error case, negative length
};

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
static MunitResult test_createQuestionMarkString(const MunitParameter params[], void *data) {
    // Silencing the compiler
    (void) data;
    (void) params;
    
    for (int i = 0; i < CREATE_QUESTION_MARK_STRING_TEST_VALUES_COUNT; i++) {
        int expectedLength = createQuestionMarkStringTestValues[i].length;
        char *expected = createQuestionMarkStringTestValues[i].generatedString;

        char *obtained = createQuestionMarkString(createQuestionMarkStringTestValues[i].length);

        munit_assert_uint32(strlen(obtained), ==, expectedLength);
        munit_assert_string_equal(obtained, expected);

        free(obtained);
    }

    return MUNIT_OK;
}
#pragma GCC diagnostic pop
