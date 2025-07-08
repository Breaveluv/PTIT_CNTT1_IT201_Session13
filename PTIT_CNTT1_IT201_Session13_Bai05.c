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


int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->arr[stack->top--];
}


void reverseArray(int arr[], int size) {
    Stack *temp = createStack(size);

    if (!temp) {
        printf("Failed to create temporary stack.\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        push(temp, arr[i]);
    }
    for (int i = 0; i < size; i++) {
        arr[i] = pop(temp);
    }
    free(temp->arr);
    free(temp);
}


void printArray( int arr[], int size) {
    printf(": [");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}


int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid input\n");
        return 1;
    }
    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        printf("Out of memory\n");
        return 1;
    }
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }





    reverseArray(arr, n);


    printArray( arr, n);


    free(arr);
    return 0;
}