#include <stdio.h>

int main(void) {
    int N = 0;
    int sumUpToCurrent = 0;
    int max = 0;

    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        int num = 0;
        scanf("%d", &num);

        sumUpToCurrent += num;
        if(max < sumUpToCurrent)
            max = sumUpToCurrent;
        
        if(sumUpToCurrent < 0)
            sumUpToCurrent = 0;
    }

    printf("%d\n", max);

    return 0;
}