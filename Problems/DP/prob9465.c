#include <stdio.h>
#include <stdlib.h>

#define TRUE        1
#define FALSE       0

// i 번째 column에서 1번째를 선택했을 경우, 2번째를 선택했을 경우, 아무것도 선택하지 않았을 경우
// DP

int sticker[2][1000000];
int DP[2][1000000];

int max(int a, int b) {
    return (a > b)? a : b;
}


int MaxSticker(int N) {
    for(int i = 0; i < 2; i++) 
        for(int j = 0; j < N; j++) 
            scanf("%d", &sticker[i][j]);
        
    DP[0][0] = sticker[0][0];
    DP[1][0] = sticker[1][0];
    DP[0][1] = DP[1][0] + sticker[0][1];
    DP[1][1] = DP[0][0] + sticker[1][1];
    
    for(int i = 2; i < N; i++) {
        DP[0][i] = max(DP[1][i-1], DP[1][i-2]) + sticker[0][i];
        DP[1][i] = max(DP[0][i-1], DP[0][i-2]) + sticker[1][i];
    }

    return max(DP[0][N-1], DP[1][N-1]);
}


int main(void) {
    int T, N;
    int i, j, t;
    

    scanf("%d", &T);

    for(t = 0; t < T; t++) {
        scanf("%d", &N);

        printf("%d\n", MaxSticker(N));
    }
    

    




    return 0;
}