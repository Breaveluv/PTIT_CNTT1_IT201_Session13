#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int item) {
    if (stack->top == stack->capacity - 1) {
        return;
    }
    stack->arr[++stack->top] = item;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->arr[stack->top--];
}

int evaluatePostfix(char* expression) {
    int length = strlen(expression);
    Stack* stack = createStack(length);

    if (!stack) return -1;

    for (int i = 0; i < length; i++) {
        char token = expression[i];

        if (token >= '0' && token <= '9') {
            push(stack, token - '0');
        } 
        else if (token == '+' || token == '-' || token == '*' || token == '/') {
            if (stack->top < 1) {
                 free(stack->arr);
                 free(stack);
                 return -1; 
            }
            int operand2 = pop(stack);
            int operand1 = pop(stack);

            switch (token) {
                case '+': push(stack, operand1 + operand2); break;
                case '-': push(stack, operand1 - operand2); break;
                case '*': push(stack, operand1 * operand2); break;
                case '/': push(stack, operand1 / operand2); break;
            }
        }
    }

    int result = pop(stack);
    
    free(stack->arr);
    free(stack);

    return result;
}

char* readDynamicLine() {
    int capacity = 10;
    int size = 0;
    char *buffer = malloc(capacity);
    if (!buffer) return NULL;

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        if (size + 1 >= capacity) {
            capacity *= 2;
            char *temp = realloc(buffer, capacity);
            if (!temp) {
                free(buffer);
                return NULL;
            }
            buffer = temp;
        }
        buffer[size++] = c;
    }
    buffer[size] = '\0';
    return buffer;
}


int main() {
    printf("Nhap vao bieu thuc dang postfix: ");
    char *expression = readDynamicLine();

    if (!expression) {
        printf("Loi cap phat bo nho.\n");
        return 1;
    }
    
    printf("Input: \"%s\"\n", expression);
    
    int result = evaluatePostfix(expression);
    
    printf("Output: %d\n", result);

    free(expression);

    return 0;
}
