#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int p_length;

int m[501][501];
int s[501][501];


int getMinMatrixChainMutiplication(int * p) {
    int i, j, k, r;
    int q;

    int matrix_size = p_length - 1;

    for(i = 0; i < matrix_size; i++)
        m[i][i] = 0;

    for(k = 2; k <= matrix_size; k++) {
        for(i = 0; i < matrix_size - k + 1; i++) {
            j = i + k - 1;
            m[i][j] = INT_MAX;
            for(r = i; r < j; r++) {
                q = m[i][r] + m[r+1][j] + p[i] * p[r+1] * p[j+1];
                if(q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = r;
                }
            }
            
        }
    }
    
    
    for(int i = 0; i < matrix_size; i++) {
        for(int j = 0; j < matrix_size; j++) {
            printf("%-3d ", m[i][j]);
        }
        printf("\n");
    }
    
    

    return m[0][matrix_size - 1];
}

int main(void) {
    int N;
    int * p;
    int i, j;

    scanf("%d", &N);
    p_length = N + 1;
    p = (int*)malloc(sizeof(int) * p_length);

    N--;
    scanf("%d %d", &p[0], &p[1]);
    getchar();

    i = 2;
    while(N--) {
        scanf("%d %d", &p[i - 1], &p[i]);
        getchar();
        i++;
    }
    
    printf("P :");
    for(i = 0; i < p_length; i++)
        printf("%d ", p[i]);
    printf("\n");
    

    printf("%d\n", getMinMatrixChainMutiplication(p));

    free(p);

    return 0;
}