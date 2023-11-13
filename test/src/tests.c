// Including µnit.
#include "../include/munit.h"

// Including test functions files.
#include "chron_getTime.c"
#include "logger_flushOutput.c"
#include "logger_handleError.c"
#include "logger_handleRuntimeError.c"
#include "logger_handleCriticalError.c"
#include "logger_debug.c"
#include "string_manipulation_intToChars.c"
#include "string_manipulation_concat.c"
#include "string_manipulation_split.c"
#include "string_manipulation_createQuestionMarkString.c"

// Defining the list of tests to execute:
static MunitTest test_array[] = {
    { (char *) "/chron/getTime", test_getTime, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char *) "/logger/flushOutput", test_flushOutput, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char *) "/logger/handleError", test_handleError, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char *) "/logger/handleRuntimeError", test_handleRuntimeError, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char *) "/logger/debug", test_debug, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char *) "/string_manipulation/intToChars", test_intToChars, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char *) "/string_manipulation/concat", test_concat, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char *) "/string_manipulation/split", test_split, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char *) "/string_manipulation/createQuestionMarkString", test_createQuestionMarkString, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    
    // Last item must be this one (it is used to identify that this is the end of the list).
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// Defining the test suite:
static const MunitSuite test_suite = {
    (char *) "",
    test_array,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
    return munit_suite_main(&test_suite, "tpnll", argc, argv);
}
