#include <stdio.h>
#include <unistd.h>
#include "../../src/string_manipulation.h"
#include "../include/munit.h"
#define WRDLEN_TEST_VALUES_COUNT 4

typedef struct {
    char *string;
    unsigned int word_length;
} WrdlenTestStruct;

WrdlenTestStruct wrdlenTestValues[WRDLEN_TEST_VALUES_COUNT] = {
    { (char *)"I", 1 },                     // Normal case
    { (char *)"I am a sentence.", 1 },      // Normal case
    { ((char *)"I am a sentence.")+2, 2 },  // Normal case
    { ((char *)"I am a sentence.")+3, 1 },  // Edge case, not at the beginning of a word
};

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
static MunitResult test_wrdlen(const MunitParameter params[], void *data) {
    // Silencing the compiler
    (void) data;
    (void) params;
    
    for (int i = 0; i < WRDLEN_TEST_VALUES_COUNT; i++) {
        unsigned int expected = wrdlenTestValues[i].word_length;
        unsigned int obtained = wrdlen(wrdlenTestValues[i].string);

        munit_assert_uint32(obtained, ==, expected);
    }

    return MUNIT_OK;
}
#pragma GCC diagnostic pop
