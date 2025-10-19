#pragma once

#include <sys/time.h>

static int cnt = 0;

void Spin(int seconds) {
    struct timeval start, now;
    gettimeofday(&start, NULL);
    do {
        gettimeofday(&now, NULL);
        // printf("%d\n", cnt);
    } while ((now.tv_sec - start.tv_sec) < seconds);
    // cnt++;
}