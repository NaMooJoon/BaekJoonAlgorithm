#include <stdio.h>
#include <stdlib.h>

void Merge(int * arr, int low, int mid, int high) {
    int left = low;
    int right = mid + 1;

    int idx = low;
    int * term = malloc(sizeof(int) * (high + 1));

    while (left <= mid && right <= high) {
        if(arr[left] <= arr[right]) {
            term[idx++] = arr[left++];
        }
        else {
            term[idx++] = arr[right++];
        }
    }

    while(left <= mid)
        term[idx++] = arr[left++];
    while(right <= high)
        term[idx++] = arr[right++];

    for(int i = low; i <= high; i++) 
        arr[i] = term[i];
    
    free(term);
}

void MergeSort(int * arr, int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);

        Merge(arr, left, mid, right);
    }
}

int main(void) {
    int N;
    int arr[1000000];

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    MergeSort(arr, 0, N-1);

    for(int i = 0; i < N; i++)
        printf("%d\n", arr[i]);


    return 0;
}