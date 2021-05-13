#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TRUE        1
#define FALSE       0

#define HEAP_LEN    2000000

clock_t start, end;
float res;

typedef struct _node
{
    int benefit;
    int weight;
} Node;

typedef struct _branbound
{
    int benefit;
    int weight;
    int bound;
    int checkedIdx;
} BranBound;

typedef BranBound* HData;
typedef int PriorityComp(HData d1, HData d2);


typedef struct _heap
{
    PriorityComp * comp;
    int numOfData;
    BranBound* heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap * ph, PriorityComp pc);
int HISEmpty(Heap * ph);

void HInsert(Heap * ph, HData data);
HData HDelete(Heap * ph);

int IsHighLeftNode(HData d1, HData d2)
{
    return (d2->bound - d1->bound);
}

void MergeTwoArea(Node arr[], int left, int mid, int right) 
{
    int fIdx = left;
    int rIdx = mid + 1;
    int insData;
    int i;

    Node * sortArr = (Node*)malloc(sizeof(Node) * (right+1));
    int sIdx = left;

    while(fIdx <= mid && rIdx <= right) {
        if((float)arr[fIdx].benefit / arr[fIdx].weight 
            >= (float)arr[rIdx].benefit / arr[rIdx].weight) 
            sortArr[sIdx] = arr[fIdx++];
        else
            sortArr[sIdx] = arr[rIdx++];

        sIdx++;
    }

    if(fIdx > mid) {
        for(i = rIdx; i <= right; i++, sIdx++)
            sortArr[sIdx] = arr[i];
    }
    else {
        for(i = fIdx; i <= mid; i++, sIdx++)
            sortArr[sIdx] = arr[i];
    }

    for(i = left; i <= right; i++) 
        arr[i] = sortArr[i];
    
    

    free(sortArr);

}

void MergeSort(Node arr[], int left, int right) 
{
    int mid;

    if(left < right) {
        // 중간 지점을 계산한다 
        mid = (left + right) / 2;

        // 둘로 나눠서 각각을 정렬한다.
        MergeSort(arr, left, mid);
        MergeSort(arr, mid+1, right);

        // 정렬된 두 배열을 병합한다.
        MergeTwoArea(arr, left, mid, right);
    }
}



int main(void) 
{
    int N;
    int Weight;
    int total_weight;
    int total_benefit;
    int max_benefit;
    int i;

    Node * Nodes;
    // node들의 개수를 random하게 만들어서 값들을 저장을 해야할 것이고
    N = 1000;
    Weight = N * 40;

    srand(time(NULL));
    
    Nodes = (Node *)malloc(sizeof(Node) * N + 1);
    for(i = 1; i <= N; i++) 
    {
        Nodes[i].benefit = rand() % 300 + 1;
        Nodes[i].weight  = rand() % 100 + 1;
    }
    // 그 node들을 각각 Greedy, DP, Branch & Bound 로 해결을 해야한다.
    MergeSort(Nodes, 1, N);
    float BoverW;
    printf("--------------------------------------------------------------\n");
    printf("가치/무게 값이 가장 큰 순서로 매번 20번째 10가지 출력\n");
    for(int i = 20; i <= 200; i += 20)
    {
        BoverW = (float)Nodes[i].benefit / Nodes[i].weight;
        printf("\t%d번째 // 가치:%d, 무게:%d, 가치/무게:%.3f\n", i, Nodes[i].benefit, Nodes[i].weight, BoverW);
    }
    printf("--------------------------------------------------------------\n\n\n");




    // Greedy

    printf("===========================Greedy=============================\n");
    start = clock();
    int restWeight = Weight;
    total_benefit = 0;
    for(i = 1; i <= N; i++)
    {
        if(restWeight > Nodes[i].weight)
        {
            total_benefit += Nodes[i].benefit;
            restWeight -= Nodes[i].weight;
        }
        else
        {
            BoverW = (float)Nodes[i].benefit / Nodes[i].weight;
            total_benefit += restWeight * BoverW;
            break;
        }
    }
    end = clock();
    res = (float)(end - start)/CLOCKS_PER_SEC;
    printf("%d번째 보석까지 담고, %d번째 보석은 원래 %dkg인데, %dkg으로 쪼개서 담았다.\n", i-1, i, Nodes[i].weight, restWeight);
    printf("Knapsack에 담을 수 있는 가장 큰 benefit은 %d이다.\n", total_benefit);
    printf("Greedy Algorithm 실행시간은 clock: %.5f이다.\n", res);
    printf("--------------------------------------------------------------\n\n\n");




    // Dynamic Programming

    printf("======================Dynamic Programming=====================\n");
    start = clock();
    int ** V = (int **)malloc(sizeof(int*) * (N+1));
    for(i = 0; i <= N; i++)
        V[i] = (int *)malloc(sizeof(int) * Weight);

    int w;
    
    for(w = 0; w < Weight; w++)
        V[0][w] = 0;
    for(i = 1; i <= N; i++) 
    {
        V[i][0] = 0;
        for(w = 1; w < Weight; w++)
        {
            if(Nodes[i].weight < w)
            {
                if(Nodes[i].benefit + V[i-1][w - Nodes[i].weight] > V[i-1][w])
                    V[i][w] = Nodes[i].benefit + V[i-1][w - Nodes[i].weight];
                else
                    V[i][w] = V[i-1][w];
            }
            else 
                V[i][w] = V[i-1][w];
        }
    }

    end = clock();
    res = (float)(end - start)/CLOCKS_PER_SEC;
    printf("Knapsack에 담을 수 있는 가장 큰 benefit은 %d이다.\n", V[N][Weight-1]);
    printf("Dynamic programming 실행시간은 clock: %.5f이다.\n", res);

    for(i = 0; i <= N; i++)
        free(V[i]);
    free(V);
    printf("--------------------------------------------------------------\n\n\n");



    // Branch & Bound

    printf("========================Branch & Bound========================\n");

    start = clock();
    total_benefit = 0;
    max_benefit = -1;
        
    BranBound* temp = (BranBound*)malloc(sizeof(BranBound));

    temp->benefit = 0;
    temp->weight = 0;
    temp->checkedIdx = 0;

    total_weight = temp->weight;
    int k = temp->checkedIdx+1;
    while(total_weight <= Weight)
    {
        total_weight += Nodes[k].weight;
        k++;
    }
    total_weight -= Nodes[k].weight;
    temp->bound = temp->benefit;
    for(i = temp->checkedIdx + 1; i < k; i++)
        temp->bound += Nodes[i].benefit;
    temp->bound += (Weight - total_weight) * Nodes[k].benefit / Nodes[k].weight;

    Heap * ph = (Heap*)malloc(sizeof(Heap));
    HeapInit(ph, IsHighLeftNode);
    HInsert(ph, temp);

    
    

    while(!HISEmpty(ph))
    {
        BranBound* n = HDelete(ph);
        
        if( (n->benefit >= max_benefit) && (Weight > n->weight + Nodes[n->checkedIdx+1].weight) )
        {
            
            BranBound * LeftNode = (BranBound*)malloc(sizeof(BranBound));
            LeftNode->checkedIdx = n->checkedIdx + 1;
            
            LeftNode->benefit = n->benefit + Nodes[LeftNode->checkedIdx].benefit;
            LeftNode->weight  = n->weight  + Nodes[LeftNode->checkedIdx].weight;
            

            total_weight = LeftNode->weight;
            int k = LeftNode->checkedIdx + 1;
            while(total_weight <= Weight)
            {
                total_weight += Nodes[k].weight;
                k++;
            }
            total_weight -= Nodes[k].weight;
            
            LeftNode->bound = LeftNode->benefit;
            for(i = LeftNode->checkedIdx + 1; i < k; i++)
                LeftNode->bound += Nodes[i].benefit;
            LeftNode->bound += (Weight - total_weight) * Nodes[k].benefit / Nodes[k].weight;

            if(LeftNode->benefit > max_benefit)
                max_benefit = LeftNode->benefit;

            //printf("----------------------------------------\n");
            //printf("benefit:%d, weight: %d, bound: %d \n",LeftNode->benefit, LeftNode->weight, LeftNode->bound);
            //printf("----------------------------------------\n");

            HInsert(ph, LeftNode);

            ///////////////////////////////////////////////////////////////////////////////////////

            BranBound * RightNode = (BranBound*)malloc(sizeof(BranBound));
            RightNode->checkedIdx = n->checkedIdx + 1;
            
            RightNode->benefit = n->benefit;
            RightNode->weight  = n->weight;

            total_weight = RightNode->weight;
            k = RightNode->checkedIdx + 1;
            while(total_weight <= Weight)
            {
                total_weight += Nodes[k].weight;
                k++;
            }
            total_weight -= Nodes[k].weight;
            
            RightNode->bound = RightNode->benefit;
            for(i = RightNode->checkedIdx + 1; i < k; i++)
                RightNode->bound += Nodes[i].benefit;
            RightNode->bound += (Weight - total_weight) * Nodes[k].benefit / Nodes[k].weight;

            if(RightNode->benefit > max_benefit)
                max_benefit = RightNode->benefit;

            //printf("----------------------------------------\n");
            //printf("benefit:%d, weight: %d, bound: %d \n",RightNode->benefit, RightNode->weight, RightNode->bound);
            //printf("----------------------------------------\n");

            HInsert(ph, RightNode);
        }
        //free(n);
    }

    end = clock();
    res = (float)(end - start)/CLOCKS_PER_SEC;
    printf("Knapsack에 담을 수 있는 가장 큰 benefit은 %d이다.\n", max_benefit);
    printf("Dynamic programming 실행시간은 clock: %.5f이다.\n", res);
    

    free(temp);
    

    return 0;
}


void HeapInit(Heap * ph, PriorityComp pc)
{
    ph->numOfData = 0;
    ph->comp = pc;
}

int HISEmpty(Heap * ph)
{
    return (ph->numOfData == 0)? TRUE : FALSE;
}


int GetParentIDX(int idx)
{
    return idx / 2;
}

int GetLChildIDX(int idx)
{
    return idx * 2;
}

int GetRChildIDX(int idx)
{
    return idx * 2 + 1;
}

int GetHiPriChildIDX(Heap * ph, int idx)
{
    if(GetLChildIDX(idx) > ph->numOfData)
        return 0;
    else if(GetLChildIDX(idx) == ph->numOfData)
        return GetLChildIDX(idx);
    else
    {
        if(ph->comp(ph->heapArr[GetLChildIDX(idx)],
                 ph->heapArr[GetRChildIDX(idx)]) < 0)
            return GetRChildIDX(idx);
        else    
            return GetLChildIDX(idx);
    }
}


void HInsert(Heap * ph, HData data)
{
    int idx = ph->numOfData + 1;

    while(idx != 1)
    {
        if(ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0)
        {
            ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
            idx = GetParentIDX(idx);
        }
        else
            break;
    }

    ph->heapArr[idx] = data;
    ph->numOfData += 1;
}

HData HDelete(Heap * ph)
{
    HData retData = ph->heapArr[1];
    HData lastElem = ph->heapArr[ph->numOfData];

    int parentIDX = 1;
    int childIDX;

    while((childIDX = GetHiPriChildIDX(ph, parentIDX)))
    {
        if(ph->comp(lastElem, ph->heapArr[childIDX]) >= 0)
            break;
            
        ph->heapArr[parentIDX] = ph->heapArr[childIDX];
        parentIDX = childIDX;
    }

    ph->heapArr[parentIDX] = lastElem;
    ph->numOfData -= 1;
    return retData;
}