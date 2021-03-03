#include <stdio.h>
#include <stdlib.h>

int numOfExpress(int num) {
    int one = 0, two = 0, three = 0;
    if(num == 0) {
        return 1;
    }
    if(num >= 1)   {
        one  = 1 * numOfExpress(num - 1);
    }
    if(num >= 2) {
        two  = 1 * numOfExpress(num - 2);
    }
    if(num >= 3) {
        three = 1 * numOfExpress(num - 3);
    }

    return one + two + three;
}


int main(void) {
    int N;
    int num;

    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &num);
        printf("%d\n", numOfExpress(num));
    }

    
    return 0;
}