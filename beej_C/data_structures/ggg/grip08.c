#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
} Node;

Node* createNode(int newVal){
    Node *newNode = (Node *)malloc(sizeof(*newNode));
    if (newNode == NULL ) return NULL;
    newNode->val = newVal;
    newNode->next = NULL;
    return newNode;
}

void insert(Node **head, int newVal, int pos){
    Node* newNode = createNode(newVal);

    if(*head == NULL) {
        *head = newNode;
        return;
    }

    if ( pos <= 0 ) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* cursor = *head;
        int curPos = 0;

        // Travel to the position you want to place
        while ( cursor->next != NULL && curPos < pos - 1 ) {
            cursor = cursor->next;
            curPos++;
        }

        // Place new node 
        newNode->next = cursor->next;
        cursor->next = newNode;
    }
}

void delete(Node** head, int pos){

    if ( *head == NULL ) return;

    Node* cursor = *head, *temp;
    int curPos = 0;

    while( curPos < pos - 1) {
        temp = cursor;  // store previous value
        cursor = cursor->next;
        curPos++;
    }   

    temp->next = cursor->next;
    free(cursor);
}


void printList(Node* head){
    Node *cursor = head;
    while( cursor != NULL ) {
        printf("%d - ", cursor->val);
        cursor = cursor->next;
    }
    printf("\n");
}

void freeList(Node* head){
    Node* cursor = head, *temp;
    while (cursor != NULL) {
        temp = cursor->next;
        free(cursor);   
        cursor = temp;
    }
}

int main(void){
    Node* head = NULL;
    insert(&head, 5, 0);
    insert(&head, 3, 0);
    insert(&head, 9, 0);
    printList(head);

    insert(&head, 11, 2);
    insert(&head, 12, 2);
    insert(&head, 13, 2);
    printList(head);

    insert(&head, 94, 999);
    insert(&head, 93, 999);
    insert(&head, 92, 999);
    printList(head);

    
    delete(&head, 4);
    delete(&head, 4);
    delete(&head, 4);
    printList(head);

    freeList(head);
    
    return 0;
}