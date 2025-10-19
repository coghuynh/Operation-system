#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <assert.h>
#include <pthread.h>
#include "common.h"

volatile int counter = 0;
int loops;

void *worker(void *arg) {
    int i;
    for (i = 0; i < loops; i++) {
        counter++;
    }
    return NULL;
}

int main(
    int argc, char *argv[]
) {
    if (argc != 2) {
        fprintf(stderr, "Usage: threads <value>\n");
        exit(1);
    }
    loops = atoi(argv[1]);
    pthread_t t1, t2;
    printf("Init\n");

    pthread_create(&t1, NULL, worker, NULL);
    pthread_create(&t2, NULL, worker, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Final counter value: %d\n", counter);
    return 0;
}