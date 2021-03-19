#include <stdio.h>
#include <string.h>


#define MAX_LEN         500002

int main(void) {
    char str[MAX_LEN];
    int N;
    int idx, max_idx;
    char command;
    char input_char;


    scanf("%s", str);
    getchar();
    scanf("%d", &N);


    max_idx = strlen(str);      // '\0'문자를 가리키는 index
    idx = max_idx - 1;          // 마지막 문자를 가리키는 index

    while(N--) {
        getchar();
        scanf("%c", &command);
        
        switch(command) {
            case 'L' :
                if(idx == -1) break;
                idx--;
                break;

            case 'D' :
                if(idx == max_idx - 1) break;
                idx++;
                break;

            case 'B' :
                if(idx == -1) break;
                for(int i = idx; i < max_idx; i++)
                    str[i] = str[i + 1];
                idx--;
                max_idx--;
                break;

            case 'P' :
                getchar();
                scanf("%c", &input_char);
                max_idx++;
                for(int i = max_idx; i > idx; i--) 
                    str[i + 1] = str[i];
                str[idx + 1] = input_char;
                idx++;
        }
    }

    printf("%s\n", str);




    return 0;
}