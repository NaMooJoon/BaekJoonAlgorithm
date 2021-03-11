#include <stdio.h>

#define MOD         10007

int main(void) {
    int DP[1001][11];
    int N;
    int i, j, total;

    scanf("%d", &N);
    // N  = 1일때 값 초기화
    for(i = 1; i <= 10; i++) 
        DP[1][i] = i;

    for(i = 2; i <= N; i++) {
        total = 0;
        for(j = 1; j <= 10; j++){
            total += DP[i-1][j];
            total %= MOD;
            DP[i][j] = total;
        }
    }

    printf("%d\n", DP[N][10] % 10007);


    return 0;
}