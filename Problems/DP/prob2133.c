#include <stdio.h>

int main(void) {
    int N;
    int DP[31] = {0,};

    scanf("%d", &N);

    DP[2] = 3;
    DP[4] = 11;
    for(int i = 6; i <= N; i += 2)
        DP[i] = 4 * DP[i - 2] - DP[i - 4];
    
    printf("%d\n", DP[N]);

    return 0;
}