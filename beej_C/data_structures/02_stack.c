#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void initStack(Stack *stack) {
    stack->top = -1; // top of list defined as -1
}

int isEmpty(Stack *stack){
    return (stack->top == -1);
}

int isFull(Stack *stack){
    return (stack->top == MAX - 1);
}

void push(Stack *stack, int value){
    if (isFull(stack)) { printf("Stack overflow, cant push"); return; }
    stack->arr[++stack->top] = value; 
}

int pop(Stack *stack) {
    if (isEmpty(stack)) { printf("Stack underflow, cant pop"); return -1; } 
    int popVal = stack->arr[stack->top--];   
    printf("popped: %d\n", popVal);
    return popVal;
}

int peek(Stack *stack){
    if (isEmpty(stack)) { printf("Stack empty, cant peek"); return -1; } 
    return stack->arr[stack->top];
}

int main(void){
    Stack myStack;
    initStack(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    printf("Top element: %d\n", peek(&myStack));

    pop(&myStack);
    pop(&myStack);
    pop(&myStack);

    pop(&myStack); // Trying to pop from an empty stack

    return 0;
}


    