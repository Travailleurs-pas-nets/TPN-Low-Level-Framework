#include <stdio.h>
#include <unistd.h>
#include "../../src/logger.h"
#include "../include/munit.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
static MunitResult test_handleError(const MunitParameter params[], void *data) {
    unsigned char obtained[100] = {0};
    unsigned char expected[100] = {
        '3', '3', '3',
        ' ',
        '4', '4', '4', '4',
        ':', ' ',
        '9', '9', '9', '9', '9', '9', '9', '9', '9', ':', ' ',
        'N', 'o', ' ', 'c', 'h', 'i', 'l', 'd', ' ', 'p', 'r', 'o', 'c', 'e', 's', 's', 'e', 's', '\n', 0
    };

    int stderr_backup;
    int pipe_fd[2];

    // Silencing the compiler
    (void) data;
    (void) params;

    // Changing stdout for a local pipe, to get what has been printed inside it.
    stderr_backup = dup(fileno(stderr));
    pipe(pipe_fd);
    dup2(pipe_fd[1], fileno(stderr));

    handleError("333", "999999999", "4444", LL_PROD);
    handleError("333", "999999999", "4444", LL_DEBUG);
    write(pipe_fd[1], "", 1); // To get a null terminated string from the pipe
    close(pipe_fd[1]);

    dup2(stderr_backup, fileno(stderr));

    // Getting the output
    read(pipe_fd[0], obtained, 100);

    munit_assert_string_equal((char *) obtained, (char *) expected);

    return MUNIT_OK;
}
#pragma GCC diagnostic pop
