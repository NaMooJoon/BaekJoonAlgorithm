#include <stdio.h>

#define MAX_NUM     400


int main(void) {
    int N, K;
    unsigned long long Combination[MAX_NUM][MAX_NUM];

    scanf("%d %d", &N, &K);
    
    // N+1 H K-1 == N+K-1 C K-1
    Combination[1][0] = Combination[1][1] = 1;

    for(int i = 2; i < N+K; i++) {
        Combination[i][0] = Combination[i][i] = 1;
        for(int j = 1 ; j < i; j++) {
            Combination[i][j] = (Combination[i-1][j-1] + Combination[i-1][j]) % 1000000000;
        }
    }
    printf("%llu\n", Combination[N+K-1][K-1]);
    


    return 0;
}