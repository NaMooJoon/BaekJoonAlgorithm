#include <stdio.h>

int main(void) {
    int N;
    int i;
    int total = 0;

    scanf("%d", &N);

    for(i = 1; i <= N; i++) 
        total += i;

    printf("%d\n", total);

    return 0;
}