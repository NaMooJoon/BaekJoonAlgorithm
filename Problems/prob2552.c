#include <stdio.h>

int main(void) {
    int bulb[30];
    int link[30];
    int N, k;
    int i;

    scanf("%d", &N);
    for(i = 0; i < N; i++)
        scanf("%d", &bulb[i]);
    
    scanf("%d", &k);

    // 전구의 수를 입력받는다.
    // 전구N부터 연결된 스위치의 번호를 입력받는다.
    // K를 입력받는다.

    // 켜지지 않는 전구들을 골라낸다.
    // 켜지는 전구들로 이진수를 만들어 낸다.
    // 이진수들을 10진수로 나열한다.
    // 정렬한다.
    // K번째 10진수 숫자를 찾아낸다.


    return 0;
}