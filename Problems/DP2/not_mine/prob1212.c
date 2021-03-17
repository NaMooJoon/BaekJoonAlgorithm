#include <stdio.h>
#include <string.h>

void print_8_2(int data) {
    static int check = 0;
    int a = 1 << 2;
    
    for(int i = 0; i < 3; i++) {
        if(a & data) {
            putchar('1');
            check++;
        }else if(check != 0) {
            putchar('0');
        }
        a = a >> 1;
    }
}

int main(void) {
    char str[333334];
    int data;
    int str_len;

    scanf("%s", str);
    str_len = strlen(str);

    if(str[0] == '0') {
        putchar('0');
        putchar('\n');

        return 0;
    }
    
    for(int i = 0; i < str_len; i++) {
        data = str[i] - '0';
        print_8_2(data);
    }
    putchar('\n');



    return 0;
}