#include <stdio.h>

#define min(X, Y)       (((X) > (Y))? (Y) : (X))


int main(void) {
    int N;
    int num;
    int count_two = 0, count_five = 0;
    int n, i;

    scanf("%d", &N);
    for(int n = 1; n <= N; n++) {
        i = n;
        while((i % 2) == 0 || (i % 5) == 0) {
            if((i % 2) == 0){
                count_two++;
                i /= 2;
            }
            if((i % 5) == 0){
                count_five++;
                i /= 5;
            }
        }
    }
    printf("%d\n", min(count_two, count_five));

    return 0;
}