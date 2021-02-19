#include <stdio.h>

int main(void) {
    int N;
    char digit;
    int total = 0;

    scanf("%d", &N);
    getchar();
    
    while(N --) {
        digit = getchar();
        total += digit - '0';
    }

    printf("%d\n", total);

    return 0;
}