#include <stdio.h>

#define MAXLEN      100

int main(void) {
    char str[MAXLEN];

    while(fgets(str, MAXLEN, stdin) != NULL) {
        printf("%s", str);
    }


    return 0;
}