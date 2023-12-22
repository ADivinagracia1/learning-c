#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void initStack(Stack* stack) {
    stack->top = NULL;
}

int isEmpty(Stack* stack){
    return (stack->top == NULL);
}

void push(Stack* stack, int newValue){
    Node* newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) { return; }
    newNode->val = newValue;
    newNode->next = stack->top;

    stack->top = newNode;
    printf("pushed %d\n", newValue);
}

int pop(Stack *stack){
    if (isEmpty(stack)) { printf("stack underflow"); return -1; }
    Node* popNode = stack->top;
    int popVal = popNode->val;
    stack->top = popNode->next; 
    free(popNode);
    return popVal;
}

int peek(Stack* stack){
    if (isEmpty(stack)) { printf("stack empty, cant peek"); return -1; }
    return stack->top->val;
}

void printStack(Stack* stack){
    Node* current = stack->top;
    printf("Stack: ");
    while (current != NULL){
        printf("%d - ", current->val);
        current = current->next;
    }
    printf("\n");
}

// MOST IMPORTANT:
void freeStack(Stack* stack){
    Node *current = stack->top, *tmp;
    while( current != NULL ) {
        tmp = current;
        current=current->next;
        free(tmp);
    }

}

int main(void){
    Stack myStack;
    initStack(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    printf("Top element: %d\n", peek(&myStack));

    printStack(&myStack);


    printf("popped value: %d\n", pop(&myStack));
    printf("popped value: %d\n", pop(&myStack));
    printf("popped value: %d\n", pop(&myStack));
    
    printf("popped value: %d\n", pop(&myStack)); // Trying to pop an empty stack

    freeStack(&myStack);

    return 0;
}


    