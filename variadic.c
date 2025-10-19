#include "stdio.h"
#include "stdarg.h"

int sum(int n, int count, ...) {
    va_list args;
    int total = 0;
    va_start(args, n);
    for (int i = 0; i < count; ++i) {
        total += va_arg(args, int);
    }
    va_end(args);
    return total;
}

int main() {
    printf("Sum: %d\n", sum(0, 4, 1, 2, 3, 4));
}