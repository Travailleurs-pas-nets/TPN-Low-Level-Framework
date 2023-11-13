#include <stdio.h>
#include <unistd.h>
#include "../../src/string_manipulation.h"
#include "../include/munit.h"
#define INT_TO_CHARS_TEST_VALUES_COUNT 8

typedef struct {
    int integer;
    char *string_representation;
} IntToCharTestStruct;

IntToCharTestStruct intToCharsTestValues[INT_TO_CHARS_TEST_VALUES_COUNT] = {
    { 3, (char *) "3" },                    // Normal case, positive value
    {-3, (char *)"-3" },                    // Normal case, negative value
    { 0, (char *) "0" },                    // Edge case, zero
    {-0, (char *) "0" },                    // Edge case, negative zero
    { 2147483647, (char *) "2147483647" },  // Edge case, max integer value (32 bits)
    {-2147483648, (char *)"-2147483648" },  // Edge case, min integer value (32 bits)
    { 107, (char *) "107" },                // Edge case, positive integer with a zero before the end
    {-107, (char *)"-107" }                 // Edge case, negative integer with a zero before the end
};

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
static MunitResult test_intToChars(const MunitParameter params[], void *data) {
    // Silencing the compiler
    (void) data;
    (void) params;
    
    for (int i = 0; i < INT_TO_CHARS_TEST_VALUES_COUNT; i++) {
        char *expected = intToCharsTestValues[i].string_representation;
        char *obtained = intToChars(intToCharsTestValues[i].integer);

        munit_assert_string_equal(obtained, expected);
    }

    return MUNIT_OK;
}
#pragma GCC diagnostic pop
