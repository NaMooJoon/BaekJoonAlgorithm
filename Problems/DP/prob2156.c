#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE        1
#define FALSE       0

int memo[10000][2][2];     // [idx번째에서][idx-2와인 마셨냐?][idx-1와인 마셨냐?]

int maximum(int a, int b) {
    return (a > b)? a : b;
}

int drinkMaximumWine(int * cups, int * drink, int N, int idx) {
    int ThisWine;       // 이번 와인을 마신 경우의 수
    int notThisWine;    // 안마신 경우의 수

    int firstWine;      // idx - 2 와인 check용
    int secondWind;     // idx - 1 와인 check용
    firstWine  =  (idx >= 2)? drink[idx - 2] : FALSE;
    secondWind =  (idx >= 1)? drink[idx - 1] : FALSE;
    
    if(idx == N)
        return 0;
    
    if(memo[idx][firstWine][secondWind] != -1)
        return memo[idx][firstWine][secondWind];
    

    if(idx >= 2 && (firstWine + secondWind) == 2) {
        drink[idx] = FALSE;
        return memo[idx][TRUE][TRUE] = drinkMaximumWine(cups, drink, N, idx + 1);
    }

    drink[idx] = FALSE;
    notThisWine = drinkMaximumWine(cups, drink, N, idx + 1);
    drink[idx] = TRUE;
    ThisWine = drinkMaximumWine(cups, drink, N, idx + 1) + cups[idx];
    
    return memo[idx][firstWine][secondWind] = maximum(notThisWine, ThisWine);

}

int main(void) {
    int N;
    int * cups;
    int * drink;

    scanf("%d", &N);

    cups = (int*)malloc(sizeof(int) * N);
    drink = (int*)malloc(sizeof(int) * N);

    for(int i = 0; i < N; i++) 
        scanf("%d", &cups[i]);
    
    memset(memo, -1, sizeof(memo));
    printf("%d\n", drinkMaximumWine(cups, drink, N, 0));



    return 0;
}