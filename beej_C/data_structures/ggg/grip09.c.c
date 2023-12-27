#include <stdio.h>
#include <stdlib.h>

#define ROW 6
#define COL 6

typedef struct Block{
    char data[ROW][COL];
} Block;

typedef struct Node{
    Block val;
    struct Node* next;
} Node;

Node* createNode( Block newVal ) {
    Node* newNode = (Node*)malloc(sizeof(*newNode));
    newNode->val = newVal;
    newNode->next = NULL;
    return newNode;
}

void insert(Node **head, Block newVal, int pos ){
    Node* newNode = createNode(newVal);
 
    if ( *head == NULL ) { 
        *head = newNode; 
        return; 
    }

    if ( pos <= 0 ) {
        newNode->next = *head;
        *head = newNode;
    } 
    else {
        Node* cursor = *head;
        int curPos = 0;

        while ( cursor->next != NULL && curPos < pos-1){
            cursor = cursor->next;
            curPos++;
        }

        newNode->next = cursor->next;
        cursor->next = newNode;
    }
}

void printList(Node* head) {
    Node* cursor = head;
    while ( cursor != NULL ) {
        // printf("%d - ", cursor->val);
        cursor = cursor->next;
    }
    printf("\n");
}

void printBlockList(Node *head) {
    Node* cursor = head;
    for ( int i = 0; i< ROW; i++ ) {
        while( cursor != NULL ) {
            Block *curBlock = &(cursor->val);
            for (int j = 0; j < COL; j++) {
                printf("%c ", curBlock->data[i][j]);
            }
            cursor = cursor->next;
        }
        cursor = head;
        printf("\n");
    }
}

void freeList(Node* head) {
    Node *cursor = head, *temp = NULL;
    while ( cursor != NULL ) {
        temp = cursor->next;
        free(cursor);
        cursor = temp;
    }
}

int main(void){
    
    Block largeG = { .data = {
        {' ', ' ', 'G', 'G', 'G', 'G'},
        {' ', 'G', ' ', ' ', ' ', ' '},
        {' ', 'G', ' ', 'G', 'G', 'G'},
        {' ', 'G', ' ', ' ', ' ', 'G'},
        {' ', 'G', ' ', ' ', ' ', 'G'},
        {' ', ' ', 'G', 'G', 'G', ' '}
    }};
    
    Block largeP = { .data = {
        {' ', 'P', 'P', 'P', 'P', ' '},
        {' ', 'P', ' ', ' ', ' ', 'P'},
        {' ', 'P', ' ', ' ', ' ', 'P'},
        {' ', 'P', 'P', 'P', 'P', ' '},
        {' ', 'P', ' ', ' ', ' ', ' '},
        {' ', 'P', ' ', ' ', ' ', ' '}
    }};

    Node* myLL = NULL;

    insert(&myLL, largeG, 999);
    insert(&myLL, largeG, 999);
    insert(&myLL, largeG, 999);
    insert(&myLL, largeP, 2);
    insert(&myLL, largeP, 2);;
    insert(&myLL, largeP, 2);
    printBlockList(myLL);

    // insert(&myLL, 6, 0);
    // insert(&myLL, 17, 0);
    // insert(&myLL, 2, 0);
    // insert(&myLL, 9, 0);
    // printList(myLL);

    // insert(&myLL, 64, 2);
    // insert(&myLL, 26, 2);
    // insert(&myLL, 2222, 999);
    // printList(myLL);



    return 0;
}

