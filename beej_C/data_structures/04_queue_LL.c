#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* head;
    Node* tail;
} Queue;

Queue* initQueue(){
    Queue *newQueue = (Queue *)malloc(sizeof(*newQueue));
    if (!newQueue) return NULL;
    newQueue->head = NULL;
    newQueue->tail = NULL;
    return newQueue;
}

Node* createNode(int newValue){
    Node* newNode = (Node *)malloc(sizeof(*newNode));
    if (newNode == NULL) { return NULL; }
    newNode->val = newValue;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(Queue* queue){
    return (queue->head == NULL);
}

// Add element at end/tail of queue
void enQueue(Queue* queue, int newValue){
    Node* newNode = createNode(newValue);
    if( isEmpty(queue) ) { queue->head = newNode; queue->tail = newNode; return; }
    queue->tail->next = newNode; // previous tail node assigns new node as the next
    queue->tail = newNode;       // assign that new node as the new tail of the queue
    printf("%d enqueued\n", queue->tail->val);
}

// Remove element at the top/head of the queue
int deQueue(Queue* queue){
    if (isEmpty(queue)) { printf("queue underflow\n"); return -1; }
    Node* deqNode = queue->head;
    int deqVal = deqNode->val;
    queue->head = deqNode->next;
    printf("%d dequeued\n", deqVal);

    // if queue is empty, update tail to be empty
    if (queue->head == NULL) { queue->tail = NULL; }

    free(deqNode);
    return deqVal;
}

int peek(Queue* queue){
    if (isEmpty(queue)) { printf("Queue empty, nothing to peek"); return -1; }
    return queue->head->val;
}

void printQueue(Queue* queue) {
    Node* current = queue->head;
    while ( current != NULL ) {
        printf("%d - ", current->val);
        current=current->next;  
    }
    printf("\n");
}

void freeQueue(Queue* queue) {

}

int main(void){
    Queue* myQueue = initQueue();

    enQueue(myQueue, 10);
    enQueue(myQueue, 20);
    enQueue(myQueue, 30);

    printQueue(myQueue);
    printf("Front element: %d\n", peek(myQueue));

    deQueue(myQueue);
    deQueue(myQueue);
    deQueue(myQueue);

    deQueue(myQueue);  // Trying to dequeue from an empty queue

    freeQueue(myQueue);

    return 0;
}