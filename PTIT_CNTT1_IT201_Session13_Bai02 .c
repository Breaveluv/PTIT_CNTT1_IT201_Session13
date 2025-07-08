#include <stdio.h>
#include <stdlib.h>
typedef struct Stack {
    int top;
    int capacity;
    int *arr;
}Stack;
Stack *createStack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (!stack) {
        return NULL;
    }
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
    if (stack->top == stack->capacity - 1) {
        return 1;

    }
    return 0;

}
void push(Stack *stack, int item) {
    if (isFull(stack)) {
        printf("Stack is full\n");
        return;
    }
    stack->arr[++stack->top] = item;
}
void display(Stack *stack) {
    printf("Stack ={ \n ");
    printf("  elements: [");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
        if (i < stack->top) {
            printf(" ,");
        }

    }
    printf("],\n");
    printf("  top: %d,\n", stack->top);
    printf("  cap: %d\n", stack->capacity);
    printf("}\n");
}
int main(void) {
    int capacity = 5;
    Stack *stack = createStack(capacity);
    if (!stack) {
        printf("Can't create stack\n");
        return 1;
    }

    printf("Nhap cac phan tu \n");
    for (int i = 1; i <= 5; i++) {
        int value;
        scanf("%d", &value);
        push(stack, value);
    }
    display(stack);
    free(stack->arr);
    free(stack);
    return 0;
}