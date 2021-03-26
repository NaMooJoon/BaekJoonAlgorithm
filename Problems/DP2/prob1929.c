#include <stdio.h>

int main(void) {
    int M, N;
    int prime[1000001] = {0,};
    int i, j;
    int num;

    scanf("%d %d", &M, &N);
    
    prime[1] = -1;
    for(i = 2; i <= N; i++) {
        if(prime[i] == -1)
            continue;
        for(j = i + i; j <= N; j += i) 
            prime[j] = -1;
    }
    


    for(i = M; i <= N; i++) {
        if(prime[i] != -1)
            printf("%d\n", i);
    }

    return 0;
}