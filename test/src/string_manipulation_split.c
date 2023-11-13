#include <stdio.h>
#include <unistd.h>
#include "../../src/string_manipulation.h"
#include "../include/munit.h"
#define SPLIT_TEST_VALUES_COUNT 13

typedef struct {
    char *string;
    char delimiter;
    char **words;
    unsigned short wordCount;
} SplitTestStruct;

static char *sentenceWords[8] = { (char *)"I", (char *)"am", (char *)"a", (char *)"sentence", (char *)"that", (char *)"has", (char *)"been", (char *)"splitted." };
static char *notSplittedSentence[1] = { (char *)"I am a sentence that could not be splitted." };
static char *emptySentence[1] = { (char *)"" };

SplitTestStruct splitTestValues[SPLIT_TEST_VALUES_COUNT] = {
    { (char *)"I am a sentence that has been splitted.", ' ', sentenceWords, 8 },           // Normal case, space delimiter
    { (char *)"I\nam\na\nsentence\nthat\nhas\nbeen\nsplitted.", '\n', sentenceWords, 8 },   // Normal case, special character delimiter
    { (char *)"I am a sentence that could not be splitted.", '_', notSplittedSentence, 1 }, // Edge case, delimiter not found
    { (char *)" I am a sentence that has been splitted.", ' ', sentenceWords, 8 },          // Edge case, first char being the delimiter
    { (char *)"I am a sentence that has been splitted. ", ' ', sentenceWords, 8 },          // Edge case, last char being the delimiter
    { (char *)" I am a sentence that has been splitted. ", ' ', sentenceWords, 8 },         // Edge case, 1st & last char being the delimiter
    { (char *)"  I am a sentence that has been splitted.", ' ', sentenceWords, 8 },         // Edge case, multiple delimiter as 1st char
    { (char *)"I am a sentence that has been splitted.  ", ' ', sentenceWords, 8 },         // Edge case, multiple delimiter at eos
    { (char *)"  I am a sentence that has been splitted.  ", ' ', sentenceWords, 8 },       // Edge case, multiple delimiter at bos & eos
    { (char *)"I am a sentence  that has been splitted.", ' ', sentenceWords, 8 },          // Edge case, multiple delimiter in the middle of sentence
    { (char *)"", ' ', emptySentence, 1 },                                                  // Edge case, empty input string
    { (char *)"-", '-', emptySentence, 1 },                                                 // Edge case, only one delimiter in the input
    { (char *)"---", '-', emptySentence, 1 }                                                // Edge case, only delimiters in the input string
};

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
static MunitResult test_split(const MunitParameter params[], void *data) {
    // Silencing the compiler
    (void) data;
    (void) params;
    
    for (int i = 0; i < SPLIT_TEST_VALUES_COUNT; i++) {
        unsigned short expectedWordCount = splitTestValues[i].wordCount;
        char **expected = splitTestValues[i].words;

        unsigned short obtainedWordCont;
        char **obtained = split(splitTestValues[i].string, splitTestValues[i].delimiter, &obtainedWordCont);

        munit_assert_uint16(obtainedWordCont, ==, expectedWordCount);

        for (int j = 0; j < expectedWordCount; j++) {
            munit_assert_string_equal(obtained[j], expected[j]);
        }

        free(obtained);
    }

    return MUNIT_OK;
}
#pragma GCC diagnostic pop
