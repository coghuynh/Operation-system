#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int cnt = 0;
    while (1) {
        char input[1000];
        // scanf("\n");
        scanf("%[^\n]%*c", input);
        // scanf("\n");
        printf("You entered: %p %d\n", input, cnt);
        if (strcmp(input, "exit") == 0) {
            break;
        }
        // cnt++;
    }
    return 0;
}