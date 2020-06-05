#include <stdio.h>
#include <stdlib.h>
#include "interpreter.h"

int main( void ) {
    char *stdin_buf;
    char **jobs;
    stdin_buf = read_input();
    jobs = parse_lines(stdin_buf);
    send_to_queue(jobs);
    free(stdin_buf);
    free(jobs);
}