#include <stdio.h>
#include <stdlib.h>

// WHEN YOU WAKE UP, WRITE THIS

typedef struct Node {
    int val;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int newVal) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->val = newVal;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at a specific position in the circular linked list
Node* insert(Node* head, int newVal, int pos) {
    Node* newNode = createNode(newVal);

    if (head == NULL) {
        newNode->next = newNode; // Point to itself to form a circular list
        return newNode;
    }

    if (pos <= 0) {
        // Insert at the beginning
        Node* last = head;
        while (last->next != head) { last = last->next; }
        newNode->next = head;
        last->next = newNode;
        return newNode;
    }

    Node* current = head;
    int curPos = 0;
    // Move to the position before the desired position
    while (curPos < pos - 1 && current->next != head) {
        current = current->next;
        curPos++;
    }
    newNode->next = current->next;
    current->next = newNode;

    return head;
}

// Function to delete a node at a specific position in the circular linked list
Node* delete(Node* head, int pos) {
    if (head == NULL) {
        printf("Circular linked list is empty.\n");
        return NULL;
    }

    Node* temp;
    if (pos == 0) {
        // Delete at the beginning
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }

        temp = head;
        head = head->next;
        last->next = head;
        free(temp);
        return head; // Update the head
    }

    Node* current = head;
    int curPos = 0;

    // Move to the position before the desired position
    while (curPos < pos - 1 && current->next != head) {
        current = current->next;
        curPos++;
    }

    if (current->next == head) {
        printf("Position %d is greater than the size of the list.\n", pos);
        return head;
    }

    temp = current->next;
    current->next = temp->next;
    free(temp);

    return head;
}

// Function to print the circular linked list
void printCircularList(Node* head) {
    if (head == NULL) {
        printf("Circular linked list is empty.\n");
        return;
    }

    Node* current = head;
    do {
        printf("%d - ", current->val);
        current = current->next;
    } while (current != head);
    printf("\n");
}

// Function to free the memory allocated for the circular linked list
void freeCircularList(Node* head) {
    if (head == NULL) {
        return;
    }

    Node *current = head, *temp;
    do {
        temp = current->next;
        free(current);
        current = temp;
    } while (current != head);
}

void performOneStep(Node** head) {
    if (*head == NULL) { printf("Circular linked list is empty.\n"); return; }
    printf("%d - ", (*head)->val);
    *head = (*head)->next;
}

int main(void) {
    Node* head = NULL;

    // Inserting elements into the circular linked list
    head = insert(head, 5, 0);
    head = insert(head, 3, 0);
    head = insert(head, 9, 2);

    // Printing the circular linked list
    printf("Circular Linked List: ");
    printCircularList(head);

    // Insert at position 1
    head = insert(head, 7, 1);
    printf("After inserting 7 at position 1: ");
    printCircularList(head);

    // Delete at position 2
    head = delete(head, 2);
    printf("After deleting at position 2: ");
    printCircularList(head);

    for (int i = 0; i < 10; i++ ) {
        performOneStep(&head);
    }

    // Freeing the memory allocated for the circular linked list
    freeCircularList(head);

    return 0;
}
