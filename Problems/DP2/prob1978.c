#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM         1001

int main(void) 
{
    int N;
    int i, j;
    int num, count = 0;
    int arr[MAX_NUM] = {0, };

    // Denote arr[i] by -1 when i is not a prime number.
    arr[0] = arr[1] = -1;
    for(i = 2; i <= MAX_NUM; i++)
    {
        if(arr[i] != -1)
            for(j = i+i; j <= MAX_NUM; j += i)
                arr[j] = -1;
    }

    scanf("%d", &N);
    while(N--)
    {
        scanf("%d", &num);
        if(arr[num] != -1)
            count ++;
    }

    printf("%d\n", count);


    return 0;
}