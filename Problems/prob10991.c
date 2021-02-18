#include <stdio.h>

int main(void) {

    int N;
    int i, j;

    scanf("%d", &N);
    i = N;

    while(i--) {
        for(j = 0; j < i; j++)
            putchar(' ');
        for(j = 0; j < (N - i); j++)
            printf("* ");
        putchar('\n');
    }


    return 0;
}