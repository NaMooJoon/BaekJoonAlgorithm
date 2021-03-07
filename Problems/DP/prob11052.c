#include <stdio.h>

#define MAX(X, Y)   (((X) > (Y))? (X) : (Y))


int main(void) {
    int N, max;
    int card[1001];
    int DP[1001];

    scanf("%d", &N);

    for(int i = 1; i <= N; i++) 
        scanf("%d", &card[i]);
    
    DP[1] = card[1];
    DP[2] = MAX(DP[1] + DP[1], card[2]);

    for(int i = 3; i <= N; i++) {
        max = card[i];
        for(int j = 1; j < i; j++)
            max = MAX(max, DP[i-j] + card[j]);
        DP[i] = max;
    }


    
    printf("%d\n", DP[N]);



    return 0;
}