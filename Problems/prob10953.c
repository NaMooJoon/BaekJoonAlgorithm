#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    int N;
    char str[10];
    int str_len;
    int total;

    scanf("%d", &N);    // 테스트 케이스 개수

    for(int i = 0; i < N; i++) {
        total = 0;      // 답을 출력할 변수
        
        scanf("%s", str);
        getchar();      // \n 문자

        str_len = strlen(str);
        for(int j = 0; j < str_len; j++) 
            if(isdigit(str[j]))          // 문자가 정수라면
                total += (str[j] - '0');

        printf("%d\n", total);
    }


    return 0;
}