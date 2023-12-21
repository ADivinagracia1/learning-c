// SOURCE:
// https://beej.us/guide/bgc/html/split/manual-memory-allocation.html

#include <stdio.h>
#include <stdlib.h>

#define ROW 6
#define COL 6

struct Block{
    char data[ROW][COL];
};

struct Node{ 
    struct Block data;
    struct Node* next;
};

struct Node* createNode(struct Block newData){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;
    return newNode;
}

void insert(struct Node** head, struct Block newData){
    struct Node* newNode = createNode(newData);
    newNode->next = *head;
    *head = newNode; 
}

void insertBack(struct Node** head, struct Block newData){
    struct Node* newNode = createNode(newData);
    struct Node* cursor = *head;
    if( *head == NULL ) { *head = newNode; return; }
    while ( cursor->next != NULL ) { cursor=cursor->next; }
    cursor->next = newNode;
}

void printList(struct Node* head){
    struct Node* cursor = head;
    while ( cursor != NULL ) {
        // printf("%c", cursor->data);
        cursor = cursor->next;
    }
    printf("\n");
}

void printListBlock(struct Node* head){
    struct Node* cursor = head;
    for (int i = 0; i < ROW; i++ ){
        while( cursor != NULL ) {
            struct Block* current = &(cursor->data);
            for ( int j = 0; j < COL; j++ ) {
                printf("%c ", current->data[i][j]);
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
    while( cursor != NULL ) {
        temp = cursor->next;
        free(cursor);
        cursor = temp;
    }
}

int main(void){
    
    struct Block largeG = { .data = {
        {' ', ' ', 'G', 'G', 'G', 'G'},
        {' ', 'G', ' ', ' ', ' ', ' '},
        {' ', 'G', ' ', 'G', 'G', 'G'},
        {' ', 'G', ' ', ' ', ' ', 'G'},
        {' ', 'G', ' ', ' ', ' ', 'G'},
        {' ', ' ', 'G', 'G', 'G', 'G'}
    }};
    
    struct Block largeO = { .data = {
        {' ', ' ', 'O', 'O', 'O', ' '},
        {' ', 'O', ' ', ' ', ' ', 'O'},
        {' ', 'O', ' ', ' ', ' ', 'O'},
        {' ', 'O', ' ', ' ', ' ', 'O'},
        {' ', 'O', ' ', ' ', ' ', 'O'},
        {' ', ' ', 'O', 'O', 'O', ' '}
    }};
        
    struct Block largeD = { .data = {
        {' ', 'D', 'D', 'D', ' ', ' '},
        {' ', 'D', ' ', ' ', 'D', ' '},
        {' ', 'D', ' ', ' ', 'D', ' '},
        {' ', 'd', ' ', ' ', 'D', ' '},
        {' ', 'd', ' ', ' ', 'D', ' '},
        {' ', 'D', 'D', 'D', ' ', ' '}
    }};

    struct Node* head = NULL;

    insertBack(&head, largeG);
    insertBack(&head, largeO);
    insertBack(&head, largeD);
    // printList(head);
    printListBlock(head);

    freeList(head);

    return 0;
}