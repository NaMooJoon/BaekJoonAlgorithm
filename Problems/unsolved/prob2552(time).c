#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 파마리터 num을 주어진 bulb로 bulb number을 만들 수 있는지 없는지 반환하는 문제
int is_bulbNumber(int* bulb, int bulb_N, int num, int* always_light_bulb) {
    int* light_bulb;
    light_bulb = (int*)malloc(sizeof(int) * bulb_N);

    
    // 숫자 num을 이진수처럼 만들기
    for(int i = bulb_N - 1; i >= 0; i--) {      // B^N부터 B^1까지 해당 이진수 입력.
        light_bulb[i] = num % 2;
        num = num / 2;
    }
    

    for(int i = 0; i < bulb_N; i++) {                   // B^1부터 시작
        if(!always_light_bulb[i]){                      // 항상 true인 bulb가 아니라면 확인을 진행.
            if(light_bulb[i]){                          // 해당 bulb에 불이 들어온다면
                for(int j = 0; j < i; j++) {            // 해당 bulb보다 index가 작은 불켜진 bulb들과 엮이는지 확인
                    if(light_bulb[j]) {
                        if(bulb[i] < bulb[j])
                            return 0;                   // false
                    }
                }
                for(int j = i + 1; j < bulb_N; j++) {   // 해당 bulb보다 index가 큰 불켜진 bulb들과 엮이는지 확인
                    if(light_bulb[j]) {
                        if(bulb[i] > bulb[j])
                            return 0;                   // false
                    }
                }
            }
        }
    }
    free(light_bulb);

    return 1;                                       // true
}

int main(void) {
    int bulb_N;
    int* bulb;
    int* always_light_bulb;
    int K;
    int count;

    scanf("%d", &bulb_N);
    bulb = (int*)malloc(sizeof(int) * bulb_N);
    always_light_bulb = (int*)malloc(sizeof(int) * bulb_N);

    for(int i = 0; i < bulb_N; i++)
        scanf("%d", &bulb[i]);
    
    scanf("%d", &K);
    // 항상 불이 켜질 수 있는 bulb 찾기
    for(int i = 0; i < bulb_N; i++) {               // B^1부터 시작
        count = 0;
        for(int j = 0; j < i; j++) {                // 해당 bulb보다 index가 작은 불켜진 bulb들과 엮이는지 확인
            if(bulb[i] < bulb[j]){
                count ++;
                always_light_bulb[i] = 0;
                break;
            }
        }
        for(int j = i + 1; j < bulb_N; j++) {       // 해당 bulb보다 index가 큰 불켜진 bulb들과 엮이는지 확인
            if(bulb[i] > bulb[j]){
                count ++;
                always_light_bulb[i] = 0;
                break;
            }
        }
        if(!count)
            always_light_bulb[i] = 1;
    }


    // 1부터 count해서 K번째 해당될때까지 is_bulbNumber(bulb, bubl_N, i)
    int max = pow(2, bulb_N);
    count = 0;
    for(int i = 0; i < max; i++) {          // 이진수 0000부터 1111까지 확인
        if(is_bulbNumber(bulb, bulb_N, i, always_light_bulb))  // 만약 bulb number가 성립된다면
            count ++;
        if(count == K) {                    // K번째 성립된 bulbnumber을 출력
            printf("%d\n", i);
            break;
        }
    }
    if(count < K)
        printf("%d\n", -1);
    
    free(bulb);
    free(always_light_bulb);

    return 0;
}