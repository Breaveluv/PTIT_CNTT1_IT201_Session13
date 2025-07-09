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

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, char item) {
    if (stack->top == stack->capacity - 1) {
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

int areBrackets(char* expression) {
    int length = strlen(expression);
    Stack* stack = createStack(length);
    if (!stack) return 0;

    for (int i = 0; i < length; i++) {
        char currentChar = expression[i];

        if (currentChar == '(' || currentChar == '[' || currentChar == '{') {
            push(stack, currentChar);
        } else if (currentChar == ')' || currentChar == ']' || currentChar == '}') {
            if (isEmpty(stack)) {
                free(stack->arr);
                free(stack);
                return 0;
            }

            char topChar = pop(stack);

            if ((currentChar == ')' && topChar != '(') ||
                (currentChar == ']' && topChar != '[') ||
                (currentChar == '}' && topChar != '{')) {
                free(stack->arr);
                free(stack);
                return 0;
            }
        }
    }

    int result = isEmpty(stack);

    free(stack->arr);
    free(stack);

    return result;
}

int main() {
    char arr[101];

    printf("Nhap vao mot bieu thuc de kiem tra dau ngoac: ");
    fgets(arr, 101, stdin);
    arr[strcspn(arr, "\n")] = 0;



    if (areBrackets(arr)) {
        printf(" true\n");
    } else {
        printf(" false\n");
    }

    return 0;
}