#include <stdio.h>
#include <stdlib.h>

#define ROW 6
#define COL 6

struct Block{
    char data[ROW][COL];
};

struct Node{
    struct Block block;
    struct Node * next;
};

struct Node* createNode(struct Block newBlock){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->block = newBlock;
    newNode->next = NULL;
    return newNode;
}

void insertFront(struct Node** head, struct Block block){
    struct Node* newNode = createNode(block);
    newNode->next = *head;
    *head = newNode;
}

void insertBack(struct Node** head, struct Block block){
    struct Node* newNode = createNode(block);
    struct Node* cursor = *head; 

    if ( *head == NULL ) { *head = newNode; return; }

    while ( cursor->next != NULL ) { cursor=cursor->next; }
    cursor->next = newNode;
}

void printNodes(struct Node* head){
    struct Node* cursor = head;
    while ( cursor != NULL ) {
        // printf("%c - ", cursor->block);
        cursor = cursor->next;
    }
    printf("\n");
}

void printNodesBlock(struct Node* head){
    struct Node* cursor = head;
    for (int i = 0; i < ROW; i++ ) {
        while ( cursor != NULL ){
            struct Block* word = &(cursor->block);
            for ( int j = 0; j < COL; j++ ){
                printf("%c", word->data[i][j]);
            }
            cursor=cursor->next;
        }
        printf("\n");
        cursor = head;
    }
}


int main(void){
    
    struct Block largeG = { .data = {
        {' ', ' ', 'G', 'G', 'G', 'G'},        
        {' ', 'G', ' ', ' ', ' ', ' '},
        {' ', 'G', ' ', 'G', 'G', 'G'},
        {' ', 'G', ' ', ' ', ' ', 'G'},
        {' ', 'G', ' ', ' ', ' ', 'G'},
        {' ', ' ', 'G', 'G', 'G', ' '},
    }};

    struct Node* head = NULL;

    insertBack(&head, largeG);
    insertBack(&head, largeG);
    printNodesBlock(head);

    // insertBack(&head, 't');
    // insertBack(&head, 'i');
    // insertBack(&head, 'm');
    // printNodes(head);

    return 0;
}
