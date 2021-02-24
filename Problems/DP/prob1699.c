#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N;
    int * arr, * memo_arr;
    int min_index = 0, max = 0, total = 0;
    int i, j;

    scanf("%d", &N);
    arr = (int*)malloc(sizeof(int) * N);
    memo_arr = (int*)malloc(sizeof(int) * N);

    // 입력값 받아들이기
    for(i = 0; i < N; i++) 
        scanf("%d", &arr[i]);

    // 0부터 i까지 배열의 합을 memo해두기
    memo_arr[0] = arr[0];
    for(i = 1; i < N; i++) 
        memo_arr[i] = memo_arr[i - 1] + arr[i];
    

    max = memo_arr[min_index];  
    // max값 구하기           
    for(i = 1; i < N; i++) {
        if(memo_arr[min_index] > memo_arr[i-1])     // memo_arr중 가장 작은값의 인덱스 찾기
            min_index = i - 1;
        if(memo_arr[min_index] >= 0) {     // memo_arr[min_index]이 양수인지 음수인지에 따라 max값 계산방법이 달라짐
            if(max < memo_arr[i])          // 양수라면 memo_arr중 가장 큰값이 max가 된다.
                max = memo_arr[i];
        }
        else {                             // 음수라면 memo_arr[i] - memo_arr[min]의 값 중 가장 큰 값 max가 된다.
            if(max < memo_arr[i] - memo_arr[min_index])
                max = memo_arr[i] - memo_arr[min_index];
        }
    }

    
    printf("%d\n", max);
    

    return 0;
}