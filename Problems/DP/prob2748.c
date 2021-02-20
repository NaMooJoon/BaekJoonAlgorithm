#include <stdio.h>
#include <string.h>

long long memo[100];

long long Fibonacci(int num) {
    if(num == 1 || num == 2) 
        return 1;
    
    if(memo[num] != 0)
        return memo[num];
    
    memo[num] = Fibonacci(num - 1) + Fibonacci(num - 2);
    return memo[num];
}


int main(void) {
    int N;
    scanf("%d", &N);

    memset(memo, 0, sizeof(memo));

    printf("%lld\n", Fibonacci(N));
    
    return 0;
}
