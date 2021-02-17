#include <stdio.h>

int main(void) {
    int N;
    int num, min, max;
    int i;

    
    scanf("%d", &N);
    scanf("%d", &num);
    min = max = num;
    for(i = 0; i < N - 1; i++) {
        scanf("%d", &num);
        if(min > num)
            min = num;
        else if(max < num)
            max = num;
    }

    printf("%d %d\n", min, max);


    return 0;
}