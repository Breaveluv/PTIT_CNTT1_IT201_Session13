#include<stdio.h>
#include<stdlib.h>
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

int isEmpty(Stack *stack) {
    if (stack->top == -1) {
        return 1;
    }
    return 0;
}
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->arr[stack->top--];
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
int main() {
    printf("TH1\n");
    Stack *stack = createStack(5);
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);
    display(stack);
    int popped = pop(stack);
    if (popped != -1) {
        printf(" %d\n", popped);
    }
    printf("TH2\n");
    Stack *stack2 = createStack(5);
    pop(stack2);
    display(stack2);


    free(stack->arr);
    free(stack);

    free(stack2->arr);
    free(stack2);
    return 0;
}