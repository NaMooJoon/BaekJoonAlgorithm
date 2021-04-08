#include <stdio.h>

int main(void) {
    int change[17] = {0, 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int value[17];
    int answer_high, answer_low, answer_sum = 0;
    int high, low, sum;

    high = 1;
    low = 1;
    value[1] = change[1];

    for(int i = 2; i < 17; i++) {
        value[i] = value[i-1] + change[i];
        if(value[i] < value[low]) {
            low = i;
            high = i;
        }
        else if(value[i] > value[high]) {
            high = i;
        }

        sum = value[high] - value[low];
        if(sum > answer_sum) {
            answer_sum = sum;
            answer_high = high;
            answer_low = low;
        }
    }

    printf("changes in subarray: ");
    for(int i = answer_low; i <= answer_high; i++) 
        printf("%d ", change[i]);
    putchar('\n');

    printf("values in subarray: ");
    for(int i = answer_low; i <= answer_high; i++) 
        printf("%d ", value[i]);
    putchar('\n');

    printf("benefit: %d\n", answer_sum);


    return 0;
}

#if 0
주먹구구해
Sum = -999999;
for(idx = 0; idx < N; idx++) {
	temp = 0;
	for(j = idx; j < N; j++) {
		temp = arr[j] - arr[idx]
		if(temp > sum)
			sum = temp;
	}
}
#endif



#if 0
FIND_highIMUM-SUBARRAY(arr, N)

V(0) = 0;
answer_low, answer_high, anwer_sum = 0;
low = 1, high = 1, sum
V(1) = arr[1]

for(int I = 2 ; I < N; I++) 
	V(I) = V(I - 1) + arr(I);
	if(V(I) < V(low))
		low = I;
		high = I;
	else if(V(I) > V(high))
		high = I;

	sum = V(high) - V(low)
	if(sum > answer_sum) 
		answer_sum = sum;
		answer_low = low;
		answer_high = high;

return (answer_sum, answer_low, answer_high);
#endif