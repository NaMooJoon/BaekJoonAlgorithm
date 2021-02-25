#include <stdio.h>
#include <string.h>

#define CODE_LEN        5002



int main(void) {
    char code[CODE_LEN];
    int DP[CODE_LEN] = {0,};
    int code_len = 0;

    code[0] = '0';
    if(fgets(&code[1], CODE_LEN, stdin) == NULL)
        return 0;
    code[strlen(code) - 1] = '\0';
    code_len = strlen(code);
    

    // 암호를 해석할 수 없는 경우
    if(code_len == 1 || code[1] == '0'){
        printf("%d\n", 0);
        return 0;
    }
    for(int i = 0; i < code_len; i++) 
        code[i] -= '0';

    // DP 구하기
    DP[0] = 1;
    for(int i = 1; i < code_len; i++) {
        int num = 10 * code[i-1] + code[i];
        // 숫자가 1~9일경우
        if(code[i] >= 1 && code[i] <= 9)
            DP[i] = (DP[i] + DP[i-1]) % 1000000;
        // 숫자가 10~26일경우
        if(num >= 10 && num <= 26) {
            DP[i] = (DP[i] + DP[i-2]) % 1000000;
        }
    
    }
    printf("%d\n", DP[code_len - 1]);

    return 0;
}