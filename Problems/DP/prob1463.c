#include <stdio.h>
#include <string.h>

int memo[1000001];

int minValue(int a, int b) {
    return (a < b)? a : b;
}

int calculateCount(int num) {
    int min = 0;
    
    if(memo[num] != -1)
        return memo[num];

    if(num % 6 == 0)
        min = minValue(calculateCount(num / 3), calculateCount(num / 2));
    else if(num % 3 == 0)
        min = calculateCount(num / 3);
    else if(num % 2 == 0)
        min = calculateCount(num / 2);
    else
        return memo[num] = calculateCount(num - 1) + 1;
    
    return memo[num] = minValue(min, calculateCount(num - 1)) + 1;
    
}

int main(void) {
    int N;

    scanf("%d", &N);
    memset(memo, -1, sizeof(memo));
    memo[1] = 0;
    memo[2] = memo[3] =  1;

    printf("%d\n", calculateCount(N));


    return 0;
}