#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node * next;
} Node;

int main(void) {
    int N, K;
    int k;
    int * arr;
    Node * curr, *post;
    Node * head = (Node*)malloc(sizeof(Node));

    scanf("%d %d", &N, &K);
    arr = (int*)malloc(sizeof(int) * N);

    curr = head;
    for(int i = 1; i <= N; i++) {
        Node * newNode = (Node*)malloc(sizeof(Node));
        newNode->data = i;
        curr->next = newNode;
        curr = curr->next;
    }
    curr->next = head->next;


    curr = head;
    for(int i = 0; i < N; i++) {
        k = K;
        Node * rNode;
        while(k--){
            post = curr;
            curr = curr->next;
        }
        arr[i] = curr->data;
        post->next = curr->next;
        rNode = curr;
        curr = post;
        free(rNode);      
    }


    printf("<");
    for(int i = 0; i < N-1; i++)
        printf("%d, ", arr[i]);
    printf("%d>\n", arr[N-1]);

    free(arr);
    free(head);

    return 0;
}