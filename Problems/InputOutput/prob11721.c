#include <stdio.h>
#include <string.h>

#define MAX_STR     102

int main(void) {
    char str[MAX_STR];
    const int print_size = 10;
    int length, i;
    
    scanf("%s", str);
    length = strlen(str);

    for(i = 0; i < length; i++) {
        printf("%c", str[i]);
        if((i+1) % print_size == 0)
            putchar('\n');
    }
    putchar('\n');

    return 0;
}