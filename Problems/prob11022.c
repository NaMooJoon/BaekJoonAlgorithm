#include <stdio.h>

int main(void) {
    int N;
    int op1, op2;
    int i;

    scanf("%d", &N);
    for(i = 0; i < N; i++) {
        scanf("%d %d", &op1, &op2);
        printf("Case #%d: %d + %d = %d\n", i + 1, op1, op2, op1 + op2);
    }


    return 0;
}