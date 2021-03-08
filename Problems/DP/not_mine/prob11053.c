#include <stdio.h>

int main(void) {
    int DP[1001];
    int N;
    int arr[1001];
    int min, max;

    scanf("%d", &N);
    arr[0] = 0;
    for(int i = 1; i <= N; i++) 
        scanf("%d", &arr[i]);
    
    DP[0] = 0;
    max = 0;
    for(int i = 1; i <= N; i++) {
        min = 0;
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i]) {
                if(min < DP[j])
                    min = DP[j];
            }
        }
        DP[i] = min + 1;

        if(max < DP[i])
            max = DP[i];
    }

    printf("%d\n", max);

    return 0;
}