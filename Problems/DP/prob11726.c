#include <stdio.h>

#define MOD         10007

int main(void) {
    int N;
    int DP[1001];

    scanf("%d", &N);

    DP[1] = 1;
    DP[2] = 2;
    for(int i = 3; i <= N; i++)
        DP[i] = (DP[i-1] + DP[i-2]) % MOD;

    printf("%d\n", DP[N]);



    return 0;
}