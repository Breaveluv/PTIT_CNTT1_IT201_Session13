#include <stdio.h>
#include <stdlib.h>
typedef struct Stack {
    int top;
    int size;
    int* arr;
}Stack;
Stack *createStack(int size) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (!stack) {
        printf("Loi cap phat bo nho");
        return NULL;

    }
    stack->size = size;
    stack->top = -1;
    stack->arr = (int *)malloc(size * sizeof(int));
    if (!stack->arr) {
        printf("Loi cap phat bo nho");
        free(stack);
        return NULL;
    }
    return stack;
}
int main() {
    int stackSize=5;
    Stack *myStack = createStack(stackSize);
    if (myStack) {
        printf("Hello World\n");
        printf("Suc chua toi da cua ngan xep : %d \n",myStack->size);
        printf("Chi so tren cung ban dau %d \n,",myStack->top);
        free(myStack->arr);
        free(myStack);

    }else {
        printf("Loi cap phat bo nho");
    }
    return 0;
}