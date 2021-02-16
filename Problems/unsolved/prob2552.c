#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// 파마리터 num을 주어진 bulb로 전구숫자를 만들 수 있는지 없는지 반환하는 문제
int is_bulbNumber(int* bulb, int bulb_N, int num, int* always_light_bulb) {
    int* light_bulb;
    light_bulb = (int*)malloc(sizeof(int) * bulb_N);

    
    // 숫자 num을 이진수처럼 만들기
    for(int i = bulb_N - 1; i >= 0; i--) {      // B^N부터 B^1까지 해당 이진수 입력.
        light_bulb[i] = num % 2;
        num = num / 2;
    }


    /*
        <확인방법>
        bulb하나하나 해당 num의 이진수에서 불이 켜질 수 있는지 확인하는 방법.

        1. bulb를 B^1부터 B^N까지 확인하는데
            1-1. 만약 어떠한 조건에서도 항상 켜질 수 있는 bulb이면 확인할 필요 x
                1-2. B^i가 num의 이진수에서 1이 아니라면 확인할 필요 x
                    1-3. B^i 이후로 있는 bulb중 B^i가 가리키는 스위치보다 왼쪽에 있으면 false 반환
                    1-4. 1.로 돌아가기
            
        윗 과정에서 해당사항없다면 true반환
    */
    for(int i = 0; i < bulb_N; i++)                    // B^1부터 시작
        if(!always_light_bulb[i])                      // 항상 true인 bulb가 아니라면 확인을 진행.
            if(light_bulb[i])                          // 해당 bulb에 불이 들어온다면
                for(int j = i + 1; j < bulb_N; j++)    // 해당 bulb보다 index가 큰 불켜진 bulb들과 엮이는지 확인
                    if(light_bulb[j]) 
                        if(bulb[i] > bulb[j])
                            return 0;                   // false
          
    
    free(light_bulb);

    return 1;                                           // true
}

int main(void) {
    int bulb_N;              
    int* bulb;                  
    int* always_light_bulb;
    int K;
    int count;

    scanf("%d", &bulb_N);
    bulb = (int*)malloc(sizeof(int) * bulb_N);              // bulb와 연결된 스위치 저장할 곳.
    always_light_bulb = (int*)malloc(sizeof(int) * bulb_N); // 항상 켜질 수 있는 bulb

    for(int i = 0; i < bulb_N; i++)
        scanf("%d", &bulb[i]);
    
    scanf("%d", &K);
    // 어떠한 조건에서도 불 키는데 상관이 없는 bulb 찾기
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
    int length = pow(2, bulb_N);
    count = 0;
    for(int i = 0; i < length; i++) {          // 이진수 0000부터 1111까지 확인
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