#include <stdio.h>

int main(void) {
    int N, min_idx, max_idx;
    int arr[1001];
    int DP[1001];

    scanf("%d", &N);

    for(int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);

    // DP[i] = D[0] ~ D[i-1] 중 최댓값 + arr[i]
    DP[0] = 0;

    for(int i = 1; i <= N; i++) {
        min_idx = 0;
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i]) {
                if(DP[min_idx] < DP[j]) {
                    min_idx = j;
                }
            }
        }

        DP[i] = DP[min_idx] + arr[i];
    }

    max_idx = 0;
    for(int i = 1; i <= N; i++) 
        if(DP[max_idx] < DP[i])
            max_idx = i;
    
    printf("%d\n", DP[max_idx]);



    return 0;
}