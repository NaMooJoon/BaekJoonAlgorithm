#include<stdio.h>
#define MAX_N 100000
              


int arr[MAX_N + 1];

int min(int a, int b) {
	if (a > b) return b;
	else return a;
}

int main()
{
	int n;
	scanf("%d", &n);


	//첫째줄은 1의 제곱의의 덧셈으로 다 채움. 
	for (int i = 1; i <= n; i++)
	{
		arr[i] = i;
	}
	int k; 
	for (k = 2; k*k <= n; k++)
	{
		for (int i = k*k; i <= n; i++)
		{
			arr[i] = min(arr[i], arr[i - (k*k)] + 1);

			
		}
	}
	printf("%d", arr[n]);
}