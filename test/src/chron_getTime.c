#include "../../src/chron.h"
#include "../include/munit.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
static MunitResult test_getTime(const MunitParameter params[], void *data) {
    unsigned int obtained;
    unsigned int expected;

    // Silencing the compiler
    (void) data;
    (void) params;

    // Not much to test here... The best we can do is to check the result of a call's length equals
    // the expected length.
    obtained = (unsigned int) strlen(getTime());
    expected = 24;

    munit_assert_uint32(obtained, ==, expected);

    return MUNIT_OK;
}
#pragma GCC diagnostic pop
