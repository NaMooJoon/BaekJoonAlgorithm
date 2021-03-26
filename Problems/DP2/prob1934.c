#include <stdio.h>
#include <string.h>

void swap(int * a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int N;
    int small, large;
    int common_multiple;
    
    
    scanf("%d", &N);

    while(N--) {
        
        scanf("%d %d", &small, &large);
        if(small > large)
            swap(&small, &large);
        
        common_multiple = large;
        while(1) {
            if(common_multiple % small == 0)
                break;
            common_multiple += large;
        }
        printf("%d\n", common_multiple);
    }



    return 0;
}