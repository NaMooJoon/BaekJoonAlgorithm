#include <stdio.h>

int main(void) {
    int N;
    int i, j;
    int left, right;

    scanf("%d", &N);
    left = right = i = N - 1;
    while(i --) {
        for(j = 0; j < left; j++)
            putchar(' ');
        putchar('*');

        if(left != right){
            for(j = 0; j < (right - left) - 1; j++)
                putchar(' ');
            putchar('*');
        }
        putchar('\n');
        left--;
        right++;
    }

    i = 2 * N - 1;
    while(i --)
        putchar('*');
    putchar('\n');


    return 0;
}