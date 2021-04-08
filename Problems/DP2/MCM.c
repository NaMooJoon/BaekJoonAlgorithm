#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>

#define MATRIX_SIZE         10000

long long m[MATRIX_SIZE][MATRIX_SIZE];

long long Top_Down_MatrixChainMultiplication(int * p, int i, int j) {
    int k;                 // index which indicates where the parentheses is
    long long count;
    
    if (m[i][j] != -1)     // Memoization       / if it is already visited
        return m[i][j];
    if (i == j)            // Smallest element  / if it does not need to multiply (Only one matrix)
        m[i][j] = 0;    
    else
    {
        m[i][j] = LLONG_MAX;
        
        // Finding minimum count of the multiplication (k from i to j-1)
        for (k = i; k < j; k++) 
        {
            count = Top_Down_MatrixChainMultiplication(p, i, k)
                    + Top_Down_MatrixChainMultiplication(p, k + 1, j)
                    + p[i-1] * p[k] * p[j];
    
            if (count < m[i][j])
                m[i][j] = count;
        }
    }
    // Return minimum count
    return m[i][j];
}


long long Bottom_Up_MatrixChainMultiplication(int * p, int matrix_size) {
    int i, j, k, r;
    long long q;

    // Where only one matrix is (it does not need to multiply, so it should be '0')
    for(i = 1; i <= matrix_size; i++)
        m[i][i] = 0;


    for(k = 2; k <= matrix_size; k++)   // k is the length of chain matrices
    {
        for(i = 1; i <= matrix_size - k + 1; i++) // i is idex which indicate starting point of chain matrices
        {
            j = i + k - 1;                        // j is idex which indicate finishing point of chain matrices
            m[i][j] = LLONG_MAX;

            // Finding minimum count of the multiplication (r from i to j-1)
            for(r = i; r <= j - 1; r++) 
            {
                q = m[i][r] + m[r+1][j] 
                    + p[i-1] * p[r] * p[j];

                if(q < m[i][j]) 
                    m[i][j] = q;
            } 
        }
    }
    
    
    // Return minimum count of multipication
    return m[1][matrix_size];
}

int main(void) {
    int N;
    int i;
    int caseSize;
    clock_t start, end;
    double result;

    srand(time(NULL));

    // caseSize is the number of Matrices.
    caseSize = 18;
    for(N = 0; N < 10; N++) {
        int * p;

        // Determine the size of the matrices in random access
        p = (int*)malloc(sizeof(int) * (caseSize + 1));
        for(i = 0; i < caseSize + 1; i++) {
            p[i] = rand() % 90 + 10;
            p[i] = p[i] - (p[i] % 10) + 10;
        }


        printf("-------------------------------CASE%d--------------------------------\n", N+1);
        // Printing size of each matrices
        for(i = 0; i < caseSize; i++) {
            printf("M[%-2dth] = (%-2d, %-2d)", (i+1), p[i], p[i+1]);
            if((i+1)%3 == 0)    putchar('\n');
            else                putchar('\t');
            if(i == 5) {
                i = caseSize - 6;
                printf("\n\t....................simplify......................\n\n");
            }
        }

        printf("\n------------------------------------------------------------------\n");
        // Printing answer and problem solving time used by Top-Down(Memoization) Dynamic Programming.
        printf("Top-Down Dynamic Programing Version //\n");
        start = clock();
        memset(m, -1, MATRIX_SIZE * MATRIX_SIZE);
        printf("Answer: %lld\n", Top_Down_MatrixChainMultiplication(p, 1, caseSize));
        end = clock();
        result = (double)(end - start);
        printf("Time  : %f\n", (result / CLOCKS_PER_SEC));


        printf("-----------------------------------------------------------------\n");
        // Printing answer and problem solving time used by Bottom-Up Dynamic Programming.
        printf("Bottom-Up Dynamic Programing Version //\n");
        start = clock();
        memset(m, 0, MATRIX_SIZE * MATRIX_SIZE);
        printf("Answer: %lld\n", Bottom_Up_MatrixChainMultiplication(p, caseSize));
        end = clock();
        result = (double)(end - start);
        printf("Time  : %f\n", (result / CLOCKS_PER_SEC));
        printf("===============================END================================\n\n");

        free(p);

        // Enlarge the caseSize(the number of matrices)
        caseSize *= 2;


    }

    

    return 0;
}