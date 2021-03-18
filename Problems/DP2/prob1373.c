#include <stdio.h>
#include <string.h>

#define MAX_LEN     1000000

int main(void) {
    char str[MAX_LEN];
    int str_len;
    int i;
    int num = 0;
    int a;

    // 8진수 한 문자당 이진수 세자리로 표현한다.
    // EX> 5 -> 101 , 7 -> 111 

    // 2진수를 문자열로 읽어들인다.
    scanf("%s", str);
    str_len = strlen(str);

    // a는 이진수 3묶음당 각 자리수에 곱해야할 2의 제곱승의 값이다.
    a = 1 << ((str_len % 3) - 1);
    for(i = 0; i < str_len % 3; i++, a = a >> 1)
        num += a * (str[i] - '0');
    // 만약 str_len이 3으로 나누어 떨어진다면 print -> X
    if(num != 0)
        printf("%d", num);

    
    while(i < str_len) {
        num = 0;
        a = 1 << 2;
        // 읽어드린 문자열 3개씩 합쳐서 8진수의 한자리 값으로 변환하는 과정
        for(int j = 0; j < 3; j++, i++, a = a >> 1)
            num += a * (str[i] - '0');
        printf("%d", num);
    }
    // 만약 input 값이 0일 경우에 0을 출력한다.
    if(num == 0)
        putchar('0');
    putchar('\n');


    return 0;
}