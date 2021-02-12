#include <stdio.h>

int main(void) {
    int N;          // 별의 size 
    int i, j;

    scanf("%d", &N);

    // 별 찍기
    for(i = 0; i < N; i++) {
        for(j = 0; j < (i+1); j++)
            putchar('*');
        putchar('\n');
    }


    return 0;
}