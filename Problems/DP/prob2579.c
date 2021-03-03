#include <stdio.h>
#include <string.h>

#define MAX_HIGHT       301
#define TRUE            1
#define FALSE           0

int steps[MAX_HIGHT];
int check[MAX_HIGHT];
int memo[MAX_HIGHT][2][2];

int MaxPoint(int idx, int N) {
    // 이번 계단을 밟았을때 최대값, 밟지 않았을때 최대값
    int ThisStep, NotThisStep;
    // 두번째 전과 바로 직전 계단을 밟았는지 않았는지 저장하는 변수
    int two_before = (idx >= 2)? check[idx - 2] : FALSE;
    int one_before = (idx >= 1)? check[idx - 1] : FALSE;

    if(idx == N) {
        // 마지막 계단은 항상 밟아야 함으로 -10000을 시켜 Max값이 될 수 없게 한다.
        if(idx > 1 && two_before && one_before){
            return -10000;
        }

        return steps[N];
    }

    // 답이 있다면 그 답을 이용
    if(memo[idx][two_before][one_before] != -1)
        return memo[idx][two_before][one_before];

    // 이전 계단 두개를 모두 밟았을때(연속된 계단 3번 밟으면 안되기 때문에)
    if(idx > 1 && two_before && one_before) {
        check[idx] = FALSE;
        return memo[idx][two_before][one_before] = MaxPoint(idx + 1, N);
    }
    
    // 두번째 이전 계단을 밟았지만 바로 이전 계단을 밟지 않았을때
    if(idx > 1 && two_before && !one_before) {
        check[idx] = TRUE;
        return memo[idx][two_before][one_before] = MaxPoint(idx + 1, N) + steps[idx];
    }

    // 만약 1번째 계단을 밟지 않았다면 2번째 계단 밟아햐함
    if(idx == 1 && check[idx-1] == FALSE) {
        check[idx] = TRUE;
        return memo[idx][two_before][one_before] = MaxPoint(idx + 1, N) + steps[idx];
    }

    check[idx] = FALSE;
    NotThisStep = MaxPoint(idx + 1, N);
    check[idx] = TRUE;
    ThisStep = MaxPoint(idx + 1, N) + steps[idx];
    

    return memo[idx][two_before][one_before] = (ThisStep > NotThisStep)? ThisStep : NotThisStep;
    
}


int main(void) {
    int N;

    scanf("%d", &N);
    for(int i = 0; i < N; i++) 
        scanf("%d", &steps[i]); 
    memset(memo, -1, sizeof(memo));
    memset(check, FALSE, sizeof(check));

    printf("%d\n", MaxPoint(0, N - 1));

    

    return 0;
}