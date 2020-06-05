#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "scheduler.h"

#define BUFFER_SIZE 1024

int queue(char ** job_list){ 
    int i = 0;
    while(job_list[i] != NULL) {
        printf("Job %d: %s\n", i, job_list[i]);
        i++;
    }
    return 0;
}