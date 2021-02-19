#include <stdio.h>

int main(void) {
    int N;
    int num1, num2;

    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d %d", &num1, &num2);
        printf("%d\n", num1 + num2);
    }


    return 0;
}