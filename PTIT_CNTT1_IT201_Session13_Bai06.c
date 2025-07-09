#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    int top;
    int capacity;
    char *arr;
} Stack;

Stack *createStack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (!stack) return NULL;
    
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (char *)malloc(stack->capacity * sizeof(char));
    
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

void push(Stack *stack, char item) {
    if (isFull(stack)) {
        return;
    }
    stack->arr[++stack->top] = item;
}

char pop(Stack *stack) {
    if (isEmpty(stack)) {
        return '\0';
    }
    return stack->arr[stack->top--];
}

int isPalindrome(char* str) {
    int length = strlen(str);
    Stack* stack = createStack(length);
    if (!stack) {
        return 0; 
    }

    for (int i = 0; i < length; i++) {
        push(stack, str[i]);
    }

    char reversed_str[length + 1];
    for (int i = 0; i < length; i++) {
        reversed_str[i] = pop(stack);
    }
    reversed_str[length] = '\0';

    int result = (strcmp(str, reversed_str) == 0);

    free(stack->arr);
    free(stack);

    return result;
}

int main() {
    char input_str[101];

    printf("Nhap vao mot chuoi de kiem tra: ");
    fgets(input_str, 101, stdin);
    input_str[strcspn(input_str, "\n")] = 0;

    if (strlen(input_str) == 0) {
        return 1;
    }
    


    if (isPalindrome(input_str)) {
        printf(" true\n");
    } else {
        printf(" false\n");
    }

    return 0;
}