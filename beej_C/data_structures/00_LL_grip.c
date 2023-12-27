#include <stdio.h>
#include <stdlib.h>

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

struct Node {
    char val;
    struct Node* next;
};

struct Node* CreateNode(char val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void InsertFront(struct Node** head, char val) {
    // struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // THIS IS WRONG
    struct Node* newNode = CreateNode(val);
    newNode->next = *head;
    *head = newNode; 

    DEBUG_PRINTLN("Inserting %c into %p", val, *head);
}

void InsertBack(struct Node** head, char val) {
    struct Node * newNode = CreateNode(val);
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
        printf("%c-", cursor->val);
        cursor = cursor->next;
    }    
    printf("\n");

    // THIS IS WRONG, WE NEED A CURSOR. We do NOT want to lose the location of head
    // while ( head ) {
    //     printf("%c\n", head->val);
    //     head = head->next;
    // }
}

void FreeMemory(struct Node* head) {
    struct Node* cursor = head;
    struct Node* temp;
    while( cursor != NULL ) {
        temp = cursor->next;    // save the next before deleting
        free(cursor);           // free the memory
        cursor = temp;          // assign cursor to next
    }
}

int main(void) {
    struct Node* head = NULL; 
    // Assignment is important, otherwise the memory has nowhere to go

    InsertBack(&head, 'p');
    InsertBack(&head, 'e');
    InsertBack(&head, 'n');
    InsertBack(&head, 'i');
    InsertBack(&head, 's');

    // InsertFront(&head, 'p');
    // InsertFront(&head, 'e');
    // InsertFront(&head, 'n');
    // InsertFront(&head, 'i');
    // InsertFront(&head, 's');
    
    PrintNode(head);

    FreeMemory(head);

    return 0;
}