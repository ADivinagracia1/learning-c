#include <stdio.h>
#include <stdlib.h>

#define ROW 6
#define COL 6

// Macro for printing (Compiler time operations)
#define DEBUG_PRINT 0
#if DEBUG_PRINT
#define DEBUG_PRINTLN(fmt, ...) \
    do { \
        fprintf(stderr, fmt "\n", ##__VA_ARGS__); \
    } while (0)
#else
#define DEBUG_PRINTLN(fmt, ...) do {} while (0)
#endif

struct Block {
    char data[ROW][COL];
};

struct Node {
    struct Block block;
    struct Node* next;
};

struct Node* CreateNode(struct Block newBlock){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->block = newBlock;
    newNode->next = NULL;
    return newNode;
}

void InsertFront(struct Node** head, struct Block newBlock) {
    // struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // THIS IS WRONG
    struct Node* newNode = CreateNode(newBlock);
    newNode->next = *head;
    *head = newNode; 

    DEBUG_PRINTLN("Inserting %c into %p", val, *head);
}

void InsertBack(struct Node** head, struct Block newBlock) {
    struct Node * newNode = CreateNode(newBlock);
    struct Node * cursor = *head; 


    // If the list is empty, make the new node the head
    if (*head == NULL) { *head = newNode; return; }

    // Traverse to end of list
    while ( cursor->next != NULL) cursor = cursor->next;
    cursor->next = newNode;

    DEBUG_PRINTLN("Inserting %c into %p", val, *head);
    
}

void PrintNode(struct Node* head) {

    struct Node* cursor = head;
    while (cursor != NULL) {
        printf("%c-", cursor->block.data[0][3]);
        cursor = cursor->next;
    }    
    printf("\n");

    // THIS IS WRONG, WE NEED A CURSOR. We do NOT want to lose the location of head
    // while ( head ) {
    //     printf("%c\n", head->val);
    //     head = head->next;
    // }
}

void PrintNodeHorz(struct Node* head) {
    struct Node* cursor = head;
    for (int i = 0; i < ROW; i++) {
        while(cursor != NULL) {
            struct Block* myBlock = &(cursor->block);
            for ( int j = 0; j < COL; j++ ) {
                printf("%c ", myBlock->data[i][j]);
            }
            cursor = cursor->next;
        }
        printf("\n");
        cursor = head;
    }
    printf("\n");
}

void FreeMemory(struct Node* head) {
    struct Node* cursor = head;
    struct Node* next;
    while( cursor != NULL ) {
        next = cursor->next;    // save the next before deleting
        free(cursor);           // free the memory
        cursor = next;          // assign cursor to next
    }
}

int main(void) {
    struct Block largeG = { .data = {
        {' ', ' ', 'G', 'G', 'G', 'G'},
        {' ', 'G', ' ', ' ', ' ', ' '},
        {' ', 'G', ' ', 'G', 'G', 'G'},
        {' ', 'G', ' ', ' ', ' ', 'G'},
        {' ', 'G', ' ', ' ', ' ', 'G'},
        {' ', ' ', 'G', 'G', 'G', ' '},
    }};

    struct Block largeE = { .data = {
        {' ', 'E', 'E', 'E', 'E', 'E'},
        {' ', 'E', ' ', ' ', ' ', ' '},
        {' ', 'E', 'E', 'E', ' ', ' '},
        {' ', 'E', ' ', ' ', ' ', ' '},
        {' ', 'E', ' ', ' ', ' ', ' '},
        {' ', 'E', 'E', 'E', 'E', 'E'},
    }};

    struct Block largeT = { .data = {
        {' ', 'T', 'T', 'T', 'T', 'T'},
        {' ', ' ', ' ', 'T', ' ', ' '},
        {' ', ' ', ' ', 'T', ' ', ' '},
        {' ', ' ', ' ', 'T', ' ', ' '},
        {' ', ' ', ' ', 'T', ' ', ' '},
        {' ', ' ', ' ', 'T', ' ', ' '},
    }};

    struct Block largeA = { .data = {
        {' ', ' ', ' ', 'A', ' ', ' '},
        {' ', ' ', 'A', 'A', ' ', ' '},
        {' ', 'A', ' ', ' ', 'A', ' '},
        {'A', 'A', 'A', 'A', 'A', 'A'},
        {'A', ' ', ' ', ' ', ' ', 'A'},
        {'A', ' ', ' ', ' ', ' ', 'A'},
    }};

    struct Block largeR = { .data = {
        {' ', ' ', 'R', 'R', 'R', ' '},
        {' ', 'R', ' ', ' ', 'R', ' '},
        {' ', 'R', ' ', ' ', 'R', ' '},
        {' ', 'R', 'R', 'R', ' ', ' '},
        {' ', 'R', ' ', ' ', 'R', ' '},
        {' ', 'R', ' ', ' ', ' ', 'R'},
    }};

    struct Block largeI = { .data = {
        {' ', 'I', 'I', 'I', 'I', ' '},
        {' ', ' ', 'I', ' ', ' ', ' '},
        {' ', ' ', 'I', ' ', ' ', ' '},
        {' ', ' ', 'I', ' ', ' ', ' '},
        {' ', ' ', 'I', ' ', ' ', ' '},
        {' ', 'I', 'I', 'I', 'I', ' '},
    }};

    struct Block largeP = { .data = {
        {' ', 'P', 'P', 'P', 'P', ' ',},
        {' ', 'P', ' ', ' ', ' ', 'P',},
        {' ', 'P', ' ', ' ', ' ', 'P',},
        {' ', 'P', 'P', 'P', 'P', ' ',},
        {' ', 'P', ' ', ' ', ' ', ' ',},
        {' ', 'P', ' ', ' ', ' ', ' ',},
    }};

    struct Block largeSpace = { .data = {
        {' ', ' ', ' ', ' ', ' ', ' ',},
        {' ', ' ', ' ', ' ', ' ', ' ',},
        {' ', ' ', ' ', ' ', ' ', ' ',},
        {' ', ' ', ' ', ' ', ' ', ' ',},
        {' ', ' ', ' ', ' ', ' ', ' ',},
        {' ', ' ', ' ', ' ', ' ', ' ',},
    }};

    struct Node* head = NULL; 
    // Assignment is important, otherwise the memory has nowhere to go

    InsertBack(&head, largeG);    
    InsertBack(&head, largeE);    
    InsertBack(&head, largeT);    
    InsertBack(&head, largeSpace);
    InsertBack(&head, largeA);
    InsertBack(&head, largeSpace);
    InsertBack(&head, largeG);  
    InsertBack(&head, largeR);  
    InsertBack(&head, largeI);  
    InsertBack(&head, largeP);  


    PrintNodeHorz(head);
    // InsertBack(&head, 'p');
    // InsertBack(&head, 'e');
    // InsertBack(&head, 'n');
    // InsertBack(&head, 'i');
    // InsertBack(&head, 's');
    // InsertFront(&head, 'p');
    // InsertFront(&head, 'e');
    // InsertFront(&head, 'n');
    // InsertFront(&head, 'i');
    // InsertFront(&head, 's');
    // PrintNode(head);

    FreeMemory(head);

    return 0;
}