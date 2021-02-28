#include <stdio.h>

#define MAX_LEN     91

int main(void) {
    int N;
    long long zero, one, temp;
    long long DP[MAX_LEN];

    scanf("%d", &N);
    
    DP[0] = 0;
    DP[1] = DP[2] = 1;
    zero = 1;
    one  = 0;
    for(int i = 3; i <= N; i++) {
        DP[i] = 2 * zero + one;
        temp = one;
        one = zero;
        zero = zero + temp;
    }

    printf("%lld\n", DP[N]);

    return 0;
}