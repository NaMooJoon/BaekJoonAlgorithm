#include <stdio.h>
#include <stdlib.h>

#define TRUE        1
#define FALSE       0

// i 번째 column에서 1번째를 선택했을 경우, 2번째를 선택했을 경우, 아무것도 선택하지 않았을 경우
// DP

int sticker[2][1000000];
int DP[1000000];


int MaxSticker(int N) {
    for(int i = 0; i < 2; i++) 
        for(int j = 0; j < N; j++) {
            scanf("%d", &sticker[i][j]);
        
    DP[0] = (sticker[0][0] > sticker[1][0])? sticker[0][0] : sticker[1][0];
    DP[1] = ()
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