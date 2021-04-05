#include <string.h>

int longestCommonSubsequence(char * text1, char * text2){
    int t1_len = strlen(text1) + 1;
    int t2_len = strlen(text2) + 1;
    
    printf("%d %d\n\n", t1_len, t2_len);
    
    int m[1001][1001];
    
    for(int i = 0; i < t1_len; i++) 
        m[i][0] = 0;
    for(int j = 0; j < t2_len; j++) 
        m[0][j] = 0
    
    for(int i = 1; i < t1_len; i++) {
        for(int j = 1; j < t2_len; j++) {
            if(text1[i-1] == text2[j-1])
                m[i][j] = m[i-1][j-1] + 1;
            else if(m[i-1][j] > m[i][j-1])
                m[i][j] = m[i-1][j];
            else
                m[i][j] = m[i][j-1];
        }
    }
    
    
    
    return m[t1_len-1][t2_len-1];
}