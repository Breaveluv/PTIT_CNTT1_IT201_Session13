#include<stdio.h>
#include<stdlib.h>

typedef struct Stack {
    int top;
    int capacity;
    int *arr;
} Stack;

Stack *createStack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (!stack) return NULL;
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int *)malloc(stack->capacity * sizeof(int));
    if (!stack->arr) {
        free(stack);
        return NULL;
    }
    return stack;
}

int isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int item) {
    if (isFull(stack)) {
        printf("Stack is full\n");
        return;
    }
    stack->arr[++stack->top] = item;
}


void displayLIFO(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Output\n");
    // Duyệt từ đỉnh (top) về đáy (0)
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->arr[i]);
    }
}

void displayState(Stack *stack) {
    printf("Input\n");
    printf("stack={\n");
    printf("  elements: [");
    if (!isEmpty(stack)) {
        for (int i = 0; i <= stack->top; i++) {
            printf("%d", stack->arr[i]);
            if (i < stack->top) {
                printf(", ");
            }
        }
    }
    printf("],\n");
    printf("  top: %d,\n", stack->top);
    printf("  cap: %d\n", stack->capacity);
    printf("}\n");
    printf("\n");
}

int main() {
    Stack *myStack = createStack(5);
    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);
    push(myStack, 40);
    push(myStack, 50);


    displayState(myStack);


    displayLIFO(myStack);


    free(myStack->arr);
    free(myStack);

    return 0;
}