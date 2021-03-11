#include <stdio.h>

int main(void) {
    int N;
    int arr[1001];
    int DP[1001];
    int max;

    // 입력값 받아들이기
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);

    // DP값 구하기
    DP[1] = 1;
    for(int i = 2; i <= N; i++) {
        max = 0;
        for(int j = 1; j < i; j++) 
            if(arr[i] < arr[j]) 
                if(max < DP[j]) 
                    max = DP[j];
                
        DP[i] = max + 1;
    }

    // 최댓값 출력하기
    max = 0;
    for(int i = 1; i <= N; i++)
        if(max < DP[i])
            max  = DP[i];
    
    printf("%d\n", max);


    return 0;
}