#include <stdio.h>

int min(int a, int b)
{
    return (a < b)?  a : b;
}

int divide_two(int n)
{
    int count = 0;
    while(n % 2 != 0)
    {
        count ++;
        n = n / 2;
    }
    return count;
}

int divide_five(int n)
{
    int count = 0;
    while(n % 5 != 0)
    {
        count ++;
        n = n / 5;
    }
    return count;
}


int main(void) {
    int n, m, k;
    int two = 0, five = 0;

    scanf("%d %d", &n, &m);
    k = n - m;

    for(int i = n; i > 0; i--)
    {
        two  += divide_two(i);
        five += divide_five(i);
    }

    for(int i = m; i > 0; i--)
    {
        two  -= divide_two(i);
        five -= divide_five(i);
    }

    for(int i = k; i > 0; i--)
    {
        two  -= divide_two(i);
        five -= divide_five(i);
    }

    printf("%d\n", min(two, five));

    return 0;
}