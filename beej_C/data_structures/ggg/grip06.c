#include <stdio.h>
#include <stdlib.h>

#define ROW 6
#define COL 6

struct Block{
    char data[ROW][COL];
};

struct Node {
    struct Block val;
    struct Node* next;
};

struct Node* createNode(struct Block newVal){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = newVal;
    newNode->next = NULL;
    return newNode;
}

void insertFront(struct Node** head, struct Block newVal){
    struct Node* newNode = createNode(newVal);
    newNode->next = *head;
    *head = newNode;
}

void insertBack(struct Node** head, struct Block newVal){
    struct Node* newNode = createNode(newVal);
    struct Node* cursor = *head;

    if ( *head == NULL ) { *head = newNode; return; }
    while ( cursor->next != NULL ){ cursor=cursor->next; }
    cursor->next = newNode; 

}

void printList(struct Node* head){
    struct Node* cursor = head;
    while ( cursor != NULL ) {
        // printf("%c - ", cursor->val);
        cursor = cursor->next;
    }
}

void printListBlock(struct Node* head){
    struct Node* cursor = head;
    for ( int i = 0; i < ROW; i++ ) {
        while( cursor != NULL ) {
            struct Block* valNow = &(cursor->val);
            for (int j = 0; j < COL; j++ ){
                printf("%c", valNow->data[i][j]);
            }
            cursor = cursor->next;
        }
        printf("\n");
        cursor = head;
    } 
}



void freeList(struct Node* head){
    struct Node* cursor = head;
    struct Node* temp;
    while( cursor != NULL ){
        temp = cursor->next; 
        free(cursor);
        cursor = temp;
    }
}

int main(void){
    
    struct Block largeT = { .data = {
        {'T', 'T', 'T', 'T', 'T', ' '},
        {' ', ' ', 'T', ' ', ' ', ' '},
        {' ', ' ', 'T', ' ', ' ', ' '},
        {' ', ' ', 'T', ' ', ' ', ' '},
        {' ', ' ', 'T', ' ', ' ', ' '},
        {' ', ' ', 'T', ' ', ' ', ' '},
    }};

    struct Node* head = NULL;
    
    insertBack(&head, largeT);
    insertBack(&head, largeT);
    insertBack(&head, largeT);
    printListBlock(head);

    freeList(head);

    return 0;
}