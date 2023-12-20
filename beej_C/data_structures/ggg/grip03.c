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

struct Node* CreateNode(struct Block newBlock) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->block = newBlock;
    newNode->next = NULL;
    return newNode;
}

void InsertFront(struct Node** head, struct Block newBlock) {
    struct Node* newNode = CreateNode(newBlock);
    newNode->next = *head;
    *head = newNode;
}

void InsertBack(struct Node** head, struct Block newBlock) {
    struct Node* newNode = CreateNode(newBlock);
    struct Node* cursor = *head; 


    if ( *head == NULL ) { *head = newNode; return; }

    while ( cursor->next != NULL ) { cursor=cursor->next; }
    cursor->next = newNode;
}

void PrintList(struct Node* head) {
    struct Node* cursor = head;
    while ( cursor != NULL ) {
        // printf("%c-", cursor->block);
        cursor=cursor->next;
    }
    printf("\n");
}

void PrintListBlock(struct Node* head) {
    struct Node* cursor = head; 
    for (int i = 0; i < ROW; i++ ) {
        while ( cursor != NULL ) {
            struct Block* myBlock = &(cursor->block);
            for (int j = 0; j < COL; j++) {
                printf("%c ", myBlock->data[i][j]);
            }
            cursor = cursor->next;
        }
        cursor = head;
        printf("\n");
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

    InsertBack(&head, largeG);
    InsertBack(&head, largeG);
    PrintListBlock(head);


    // InsertBack(&head, 'h');
    // InsertBack(&head, 'e');
    // InsertBack(&head, 'l');
    // InsertBack(&head, 'l');
    // InsertBack(&head, 'o');
    // InsertFront(&head, 'h');
    // InsertFront(&head, 'e');
    // InsertFront(&head, 'l');
    // InsertFront(&head, 'l');
    // InsertFront(&head, 'o');
    // PrintList(head);

    return 0;
}