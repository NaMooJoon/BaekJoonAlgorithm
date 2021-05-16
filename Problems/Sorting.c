#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(a, b) {int tmp=(a); (a)=(b); (b)=tmp;} 

clock_t start, end;
double res;

void printArr(int * arr, int size);
typedef void SORT(int * arr, int size);

// InsertionSort ///////////////////
void InsertionSort(int * arr, int N);


// HeapSort ////////////////////////
int leftChildIdx(int idx);
int rightChildIdx(int idx);

void MaxHeapify(int * arr, int idx, int size);

void Build_MaxHeap(int * arr, int size);

void HeapSort(int * arr, int size);


// QuickSort ///////////////////////
int partition(int * arr, int p, int r);

void _QuickSort(int * arr, int p, int r);
void QuickSort(int * arr, int size);


// printArr -> print first 20 parts of array,
//                  and last 20 parts of array.                
void printArr(int * arr, int size);


// makeRandomUnsortedArray -> input random values in array.
    // input same value into srand() for make a same unsorted array.
void makeRandomUnsortedArray(int * arr, int size);


// print_TimeAndResultOfSortingBy -> print time and sorting result for parameter sort
void print_TimeAndResultOfSortingBy(SORT * sort, int * arr, int N);


int main(void)
{
    int N = 10;
    int i;
    int * arr;
    while(N <= 100)
    {
        arr = (int *)malloc(sizeof(int) * (N+1));
        printf(">>> N is %d.\n\t", N);
        makeRandomUnsortedArray(arr, N);
        
        for(i = 1; i <= N; i++)
        {
            printf("%d ", arr[i]);
            if(i % 10 == 0)
                printf("\n\t");
        }
        printf("\n");
        N += 10;
    }
    N = 10;
    while(N <= 10000)
    {
        printf("******************* N = %d ********************\n", N);
        arr = (int *)malloc(sizeof(int) * (N+1));

        
        printf("-----------------Insertion Sort-----------------\n");
        print_TimeAndResultOfSortingBy(InsertionSort, arr, N);
        printf("------------------------------------------------\n");


        printf("--------------------Heap Sort-------------------\n");
        print_TimeAndResultOfSortingBy(HeapSort, arr, N);
        printf("------------------------------------------------\n");


        printf("--------------------Quick Sort------------------\n");
        print_TimeAndResultOfSortingBy(QuickSort, arr, N);
        printf("------------------------------------------------\n");

        printf("************************************************\n");
        N = (N < 100)? N += 10 : N *= 10;
    }
    return 0;
}


// InsertionSort ///////////////////
void InsertionSort(int * arr, int N)
{
    int i, j;
    int key;
    for(j = 2; j <= N; j++)
    {
        key = arr[j];
        i = j - 1;
        while(i >= 1  &&  arr[i] > key)
        {
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;
    }
}
////////////////////////////////////


// HeapSort ////////////////////////
int leftChildIdx(int idx)
{
    return (2 * idx);
}

int rightChildIdx(int idx)
{
    return (2 * idx + 1);
}

void MaxHeapify(int * arr, int idx, int size)
{
    int leftIdx = leftChildIdx(idx);
    int rightIdx = rightChildIdx(idx);
    int largestNodeIdx;

    if(leftIdx <= size  &&  arr[leftIdx] > arr[idx])
        largestNodeIdx = leftIdx;
    else
        largestNodeIdx = idx;

    if(rightIdx <= size  &&  arr[rightIdx] > arr[largestNodeIdx])
        largestNodeIdx = rightIdx;
    
    if(largestNodeIdx != idx)
    {
        SWAP(arr[idx], arr[largestNodeIdx]);
        MaxHeapify(arr, largestNodeIdx, size);
    }
}

void Build_MaxHeap(int * arr, int size)
{
    for(int idx = size/2; idx > 0; idx--)
        MaxHeapify(arr, idx, size);
}

void HeapSort(int * arr, int size)
{
    Build_MaxHeap(arr, size);

    for(int idx = size; idx > 1; idx--)
    {
        SWAP(arr[1], arr[size]);
        size = size - 1;
        MaxHeapify(arr, 1, size);
    }
}
////////////////////////////////////

// QuickSort ///////////////////////
int partition(int * arr, int p, int r)
{
    int x = arr[r];
    int i = p - 1;
    int j;

    for(j = p; j < r; j++)
    {
        if(arr[j] <= x)
        {
            i++;
            SWAP(arr[i], arr[j]);
        }
    }
    SWAP(arr[i+1], arr[r])

    return i + 1;
}

void _QuickSort(int * arr, int p, int r)
{
    if(p < r)
    {
        int q = partition(arr, p, r);
        _QuickSort(arr, p, q-1);
        _QuickSort(arr, q+1, r);
    }
}

void QuickSort(int * arr, int size)
{
    _QuickSort(arr, 1, size);
}
////////////////////////////////////


// printArr -> print first 20 parts of array,
//                  and last 20 parts of array.                
void printArr(int * arr, int size)
{
    printf("\t");
    for(int i = 1; (i <= size && i <= 20); i++)
    {
        printf("%d ", arr[i]);
        if(i % 10 == 0)
            printf("\n\t");
    }
    printf("\t...\n\t");

    if(size > 20)
    {
        for(int i = size - 19; i <= size; i++)
        {
            printf("%d ", arr[i]);
            if(i % 10 == 0)
                printf("\n\t");
        }
    }
    printf("\n");
}

// makeRandomUnsortedArray -> input random values in array.
    // input same value into srand() for make a same unsorted array.
void makeRandomUnsortedArray(int * arr, int size)
{
    srand(21800179);
    for(int i = 1; i <= size; i++)
        arr[i] = rand() % size + 1;
}


// print_TimeAndResultOfSortingBy -> print time and sorting result for parameter sort
void print_TimeAndResultOfSortingBy(SORT * sort, int * arr, int N)
{
    makeRandomUnsortedArray(arr, N);
    printf("Before sorting : \n");
    printArr(arr, N);

    start = clock();
    sort(arr, N);
    end = clock();

    printf("After sorting : \n");
    printArr(arr, N);

    res = (double)(end - start);
    printf("Time : %.5lf clock ticks.\n", res);
}