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
    struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
    NewNode->block = newBlock;
    NewNode->next = NULL;
    return NewNode;
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
    // if ( head == NULL ) { head = &newNode; return; } // THIS IS WRONG CODE

    while ( cursor->next != NULL ) cursor = cursor->next;
    cursor->next = newNode;

}

void PrintList(struct Node* head) {
    struct Node* cursor = head;
    while ( cursor != NULL ) {
        // printf("%c-", cursor->block);
        cursor = cursor->next;
    }
    printf("\n");
}

void PrintListBlock(struct Node* head) {
    struct Node* cursor = head;
    for ( int i = 0; i < ROW; i++ ) {
        while ( cursor != NULL ) {
            for ( int j = 0; j < COL; j++ ) {
                struct Block* now = &(cursor->block);
                printf("%c ", now->data[i][j]);
            }
            cursor = cursor->next; 
        }
        cursor = head;
        printf("\n");
    }
}

void FreeList(struct Node* head) {
    struct Node * cursor = head;
    struct Node * nextN;
    while ( cursor != NULL ) {
        nextN = cursor->next;
        free(cursor);
        cursor = nextN;
    }
}

int main(void){

    struct Block LargeT = { .data = {
        {'T', 'T', 'T', 'T', 'T', ' '},
        {' ', ' ', 'T', ' ', ' ', ' '},
        {' ', ' ', 'T', ' ', ' ', ' '},
        {' ', ' ', 'T', ' ', ' ', ' '},
        {' ', ' ', 'T', ' ', ' ', ' '},
        {' ', ' ', 'T', ' ', ' ', ' '},
    }};

    struct Node* head = NULL;

    InsertBack(&head, LargeT);
    InsertBack(&head, LargeT);
    InsertBack(&head, LargeT);
    PrintListBlock(head);


    // InsertBack(&head, 'T');
    // InsertBack(&head, 'o');
    // InsertBack(&head, 'd');
    // InsertBack(&head, 'o');
    // InsertFront(&head, 'T');
    // InsertFront(&head, 'o');
    // InsertFront(&head, 'd');
    // InsertFront(&head, 'o');
    // PrintList(head);

    FreeList(head);

    return 0;
}