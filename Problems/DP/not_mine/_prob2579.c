#include <stdio.h>
#define max(a, b) ((a) > (b)? (a): (b))
int S[301], D[301];

int main() {
	int stair;
	scanf("%d", &stair);

	for (int i = 1; i <= stair; i++)
		scanf("%d", S + i);
	
	D[1] = S[1], D[2] = S[1] + S[2];
	for (int i = 3; i <= stair; i++)
		D[i] = max(S[i] + D[i - 2], S[i] + S[i - 1] + D[i - 3]);
	printf("%d\n", D[stair]);
}