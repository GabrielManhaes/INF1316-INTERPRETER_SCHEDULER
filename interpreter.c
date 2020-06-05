#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "scheduler.h"
#include "interpreter.h"

#define BUFFER_SIZE 1024

char * read_input( void ) {
    char buf[1];
    char *str = malloc(sizeof(char) * BUFFER_SIZE);
    while(read(0, buf, sizeof(buf)) > 0) {
        strncat(str,(const char *) &buf, 1);
    }
    return str;
}

char ** parse_lines( char * commands ) {
    int i = 0;
    char *pntr = NULL;
    char **aux = malloc(sizeof(char *) * BUFFER_SIZE);
    char **output = malloc(sizeof(char *) * BUFFER_SIZE);
    pntr = strtok(commands, "\r\n");
    while (pntr != NULL) {
        aux[i] = malloc(sizeof(char) * (strlen(pntr) + 1));
        aux[i] = strdup(pntr);
        pntr = strtok(NULL, "\r\n");
        i++;
    }
    i = 0;
    while (aux[i] != NULL) {
        pntr = strtok(aux[i], " ");
        while (!strcmp(pntr, "exec")) pntr=strtok(NULL," ");
        output[i] = malloc(sizeof(char) * (strlen(pntr) + 1));
        output[i] = strdup(pntr);
        i++;
    }
    free(aux);
    return output;
}

int send_to_queue( char ** job_list ) {
    queue(job_list);
    return 0;
}
