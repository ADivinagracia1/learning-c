#include <stdio.h>
#include <stdlib.h>

// WHEN YOU WAKE UP, WRITE THIS

typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* createNode(int newVal) {
    Node* newNode = (Node*)malloc(sizeof(*newNode));
    if ( newNode == NULL ) return NULL;
    newNode->val = newVal;
    newNode->next = NULL;
    return newNode;
}

Node* insert(Node* head, int newVal, int pos) {
    Node* newNode = createNode(newVal);

    if ( head == NULL ) {
        newNode->next = newNode; // MOST IMPORTANT LINE
        return newNode;
    }

    if (pos <= 0) {
        Node* tail = head;
        while( tail->next != head ) { tail = tail->next; }
        newNode->next = head;
        tail->next = newNode;
        return newNode;
    }

    Node* cursor = head;
    int curPos = 0;
    while( curPos < pos - 1 && cursor->next != head ) {
        cursor = cursor->next;
        curPos++;
    }
    newNode->next = cursor->next;
    cursor->next = newNode;

    return head;
}

Node* delete(Node* head, int pos) {
    
    Node* temp = NULL;

    if (head == NULL) return NULL;

    if ( pos <= 0 ) {
        Node* tail = head; 
        while( tail->next != head ) { tail = tail->next; }
        temp = head;
        head = head->next;
        tail->next = head;
        free(temp);
        return head;
    }

    Node* cursor = head; 
    int curPos = 0;
    while( curPos < pos - 1 && cursor->next != head ) {
        cursor = cursor->next;
        curPos++;
    }
    // temp = cursor;
    // cursor = cursor->next;
    temp = cursor->next;
    cursor->next = temp->next;
    free(temp);

    return head;
}

void printList(Node* head){
    Node* cursor = head;
    do {
        printf("%d - ", cursor->val);
        cursor = cursor->next;
    } while ( cursor != head );
    printf("\n");
}

void freeCList(Node* head){
    Node* cursor = head, *temp = NULL;
    do {
        temp = cursor->next;
        free(cursor);
        cursor = temp;
    } while(cursor != head);
}

void performOneStep(Node** head) {
    if (*head == NULL) { printf("Circular linked list is empty.\n"); return; }
    printf("%d - ", (*head)->val);
    *head = (*head)->next;
}

int main(void) {

    Node* head = NULL;

    // // Inserting elements into the circular linked list
    head = insert(head, 5, 0);
    head = insert(head, 3, 0);
    head = insert(head, 9, 2);
    head = insert(head, 57, 2);
    head = insert(head, 12, 2);
    head = insert(head, 9999, 2);

    // Printing the circular linked list
    printf("Circular Linked List: ");
    printList(head);

    // // Delete at position 2
    head = delete(head, 2);
    head = delete(head, 2);
    printf("After deleting: ");
    printList(head);

    // Just to prove that the list is circular
    for (int i = 0; i < 10; i++ ) {
        performOneStep(&head);
    }

    freeCList(head);

    return 0;
}
