#include <stdio.h>
#include <string.h>
#include <math.h>

int memo[100000];

int minValue(int a, int b) {
    return (a < b)? a : b;
}

int minNumOfTerm(int num) {
    int min;
    int term = (int)sqrt(num);
    int len = (int)sqrt(num - term*term);

    if(memo[num] != -1)
        return memo[num];
    
    min = minValue(minNumOfTerm(num - term*term), minNumOfTerm(num - (term-1)*(term-1)));
    for(int i = term - 2; i > len; i--) 
        min = minValue(min, minNumOfTerm(num - i*i));
    
    return memo[num] = min + 1;
}

int main(void) {
    int N, i;

    scanf("%d", &N);
    memset(memo, -1, sizeof(memo));
    i = 4;
    while(i--) memo[i] = i;
    printf("%d\n", minNumOfTerm(N));

    return 0;
}