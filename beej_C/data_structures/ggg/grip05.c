#include <stdio.h>
#include <stdlib.h>

#define ROW 6
#define COL 6

struct Block{
    char data[ROW][COL];
};

struct Node{
    struct Block block;
    struct Node* next;
};

struct Node* createNode(struct Block newBlock){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->block = newBlock;
    newNode->next = NULL;
    return newNode;
}

void insertFront(struct Node** head, struct Block newBlock){
    struct Node* newNode = createNode(newBlock);
    newNode->next = *head;
    *head = newNode;
}

void insertBack(struct Node** head, struct Block newBlock){
    struct Node* newNode = createNode(newBlock);
    struct Node* cursor = *head; 
    if ( *head == NULL ) { *head = newNode; return; }   
    while ( cursor->next != NULL ) { cursor=cursor->next; }
    cursor->next = newNode;
    // #### Cheated: Below lines are COMPLETELY UNECESARY
    // cursor = *head;      
    // *head = cursor;
}

void printList(struct Node* head){
    struct Node* cursor = head;
    while ( cursor != NULL ) {
        // printf("%c - ", cursor->block);
        cursor = cursor->next;
    }
}

void freeList(struct Node* head){
    struct Node* cursor = head;
    struct Node* temp; 
    while ( cursor->next != NULL ){
        temp = cursor->next;
        free(cursor);
        cursor = temp;
    }
}

void printListBlocks(struct Node* head){
    struct Node* cursor = head; 
    for (int i = 0; i < ROW; i++ ) {
        while( cursor != NULL) {
            struct Block* newBlock = &(cursor->block);
            for (int j = 0; j < COL; j++ ) {
                printf("%c ", newBlock->data[i][j]);
            }
            cursor=cursor->next;
        }
        cursor=head;
        printf("\n");
    }
    printf("\n");
}

int main(void){

    struct Block largeG = { .data = {
        {' ', ' ', ' ', 'G', 'G', 'G', },
        {' ', ' ', 'G', ' ', ' ', ' ', },
        {' ', ' ', 'G', ' ', 'G', 'G', },
        {' ', ' ', 'G', ' ', ' ', 'G', },
        {' ', ' ', 'G', ' ', ' ', 'G', },
        {' ', ' ', ' ', 'G', 'G', ' ', },
    }};

    struct Node* head = NULL;

    insertBack(&head, largeG);
    insertBack(&head, largeG);
    insertBack(&head, largeG);
    printListBlocks(head);

    // insertBack(&head, 'i');
    // insertBack(&head, 't');
    // insertBack(&head, 'a');


    // insert(&head, 'p');
    // insert(&head, 'i');
    // insert(&head, 't');
    // insert(&head, 'a');
    // insert(&head, 'h');
    // printList(head);
    
    freeList(head);

    return 0;
}