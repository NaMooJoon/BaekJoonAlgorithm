
#include <stdio.h>
#include <string.h>

long long memo[100];

int main(void) {
    int N;
    scanf("%d", &N);

    memset(memo, 0, sizeof(memo));
    memo[0] = 0LL;
    memo[1] = 1LL;
    for(int i = 2; i <= N; i++) 
        memo[i] = memo[i-1] + memo[i-2];
    
    printf("%lld\n", memo[N]);
    
    return 0;
}