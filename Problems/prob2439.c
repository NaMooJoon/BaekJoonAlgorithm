#include <stdio.h>

int main(void) {
    int N;
    int i, j;

    scanf("%d", &N);

    for(i = 0; i < N; i++) {
        for(j = 0; j < (N - (i+1)); j++) 
            putchar(' ');
        for(j = 0; j < (i+1); j++)
            putchar('*');
        putchar('\n');
    }


    return 0;
}