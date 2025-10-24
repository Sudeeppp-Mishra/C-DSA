#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char arr[MAX_SIZE];
    int top;
} stack;

void initialize(stack *s) {
    s->top = -1;
}

int isEmpty(stack *s) {
    return s->top == -1;
}

int isFull(stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(stack *s, char value) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        exit(1);
    }
    s->arr[++s->top] = value;
}

char pop(stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return s->arr[s->top--];
}

char peek(stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        exit(1);
    }
    return s->arr[s->top];
}

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

void infixToPostfix(char *infix, char *postfix) {
    stack myStack;
    initialize(&myStack);
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        if (isdigit(infix[i]) || isalpha(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(&myStack, '(');
        } else if (infix[i] == ')') {
            while (!isEmpty(&myStack) && peek(&myStack) != '(') {
                postfix[j++] = pop(&myStack);
            }
            if (!isEmpty(&myStack) && peek(&myStack) == '(') {
                pop(&myStack); // Discard the '('
            }
        } else {
            while (!isEmpty(&myStack) && precedence(infix[i]) <= precedence(peek(&myStack))) {
                postfix[j++] = pop(&myStack);
            }
            push(&myStack, infix[i]);
        }
        i++;
    }

    while (!isEmpty(&myStack)) {
        postfix[j++] = pop(&myStack);
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression:\n%s\n", postfix);

    return 0;
}
