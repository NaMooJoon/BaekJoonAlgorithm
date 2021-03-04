#include <stdio.h>

#define MAX_NUM     101

long long Padovan(long long DP[], int N) {
    for(int i = 5; i <= N; i++) 
            DP[i] = DP[i-1] + DP[i-5];
    
    return DP[N];
}

int main(void) {
    long long DP[MAX_NUM];
    int T, num;

    DP[0] = 0;
    DP[1] = DP[2] = DP[3] = 1;
    DP[4] = 2;

    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        scanf("%d", &num);
        printf("%lld\n", Padovan(DP, num));
    }




    return 0;
}