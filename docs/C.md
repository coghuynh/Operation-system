# C Note

## Pointer Note

1. Change pointer of pointer:

- Example:
```c

void swap(char* a, char* b); //it doesn't work;

void swap(char** a, char** b); //it workes. Why?

int main() {
    char** list_string; //example :))
    swap(&list_string[i], &list_string[j]);
}

```

Because `list_string` is how pointers to the start of the string. So when we need to change the pointer when pass through another function, we need to modify the element hold that pointer.


## Variadic Function

Allow flexibility in number of params

```c

#include "stdarg.h"

int sum(int count, ...) {
    va_list arg;
    va_start(arg, count);

    int total = 0;
    for (int i = 0; i < count; ++i) total += va_arg(arg, int);
    return total;
}

```

## Memory allocation:

- calloc
- malloc
- realloc