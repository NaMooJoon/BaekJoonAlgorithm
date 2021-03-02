#include <stdio.h>
#include <string.h>

#define MAX_HIGHT       301
#define TRUE            1
#define FALSE           0

int steps[MAX_HIGHT];
int check[MAX_HIGHT];
int memo[MAX_HIGHT][1][1];

int MaxPoint(int idx, int N) {
    int ThisStep, NotThisStep;
    
    int two_before = (idx >= 2)? check[idx - 2] : FALSE;
    int one_before = (idx >= 1)? check[idx - 1] : FALSE;

    if(idx == N) {
        if(idx > 1 && two_before && one_before)
            return memo[idx][two_before][one_before] = steps[N] - ((two_before > one_before)? steps[idx-2] : steps[idx-1]);

        return memo[idx][two_before][one_before] = steps[N];
    }
    if(memo[idx][two_before][one_before] != -1) 
        return memo[idx][two_before][one_before];

    if(idx > 1 && two_before && one_before) {
        check[idx] = FALSE;
        return memo[idx][two_before][one_before] = MaxPoint(idx + 1, N);
    }

    check[idx] = TRUE;
    ThisStep = MaxPoint(idx + 1, N);
    check[idx] = FALSE;
    NotThisStep = MaxPoint(idx + 1, N);

    return memo[idx][two_before][one_before] = (ThisStep > NotThisStep)? ThisStep + steps[idx] : NotThisStep;
    
}


int main(void) {
    int N;

    scanf("%d", &N);
    for(int i = 0; i < N; i++) 
        scanf("%d", &steps[i]); 
    memset(memo, -1, sizeof(memo));
    memset(check, FALSE, sizeof(check));

    printf("%d\n", MaxPoint(0, N - 1));


    

    return 0;
}