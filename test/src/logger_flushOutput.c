#include <stdio.h>
#include <unistd.h>
#include "../../src/logger.h"
#include "../include/munit.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
static MunitResult test_flushOutput(const MunitParameter params[], void *data) {
    unsigned char obtained[10] = {0};
    unsigned char expected[10] = {'\n', 0};

    int stdout_backup;
    int pipe_fd[2];

    // Silencing the compiler
    (void) data;
    (void) params;

    // Changing stdout for a local pipe, to get what has been printed inside it.
    stdout_backup = dup(fileno(stdout));
    pipe(pipe_fd);
    dup2(pipe_fd[1], fileno(stdout));

    flushOutput(LL_PROD);
    flushOutput(LL_DEBUG);
    write(pipe_fd[1], "", 1); // To get a null terminated string from the pipe
    close(pipe_fd[1]);

    dup2(stdout_backup, fileno(stdout));

    // Getting the output
    read(pipe_fd[0], obtained, 9);

    munit_assert_string_equal((char *) obtained, (char *) expected);

    return MUNIT_OK;
}
#pragma GCC diagnostic pop
