#include <stdio.h>
#include <stdlib.h>

// WHEN YOU WAKE UP, WRITE THIS

typedef struct Node {
    int val;
    struct Node* next;
} Node;


int main(void) {
    Node* head = NULL;

    printf("hello\n");

    // // Inserting elements into the circular linked list
    // head = insert(head, 5, 0);
    // head = insert(head, 3, 0);
    // head = insert(head, 9, 2);

    // // Printing the circular linked list
    // printf("Circular Linked List: ");
    // printCircularList(head);

    // // Insert at position 1
    // head = insert(head, 7, 1);
    // printf("After inserting 7: ");
    // printCircularList(head);

    // // Delete at position 2
    // head = delete(head, 2);
    // printf("After deleting at position 2: ");
    // printCircularList(head);

    // for (int i = 0; i < 10; i++ ) {
    //     performOneStep(&head);
    // }

    // // Freeing the memory allocated for the circular linked list
    // freeCircularList(head);

    return 0;
}
