#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x) {
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

void main() {
    char exp[100];
    char x;
    int i = 0;

    printf("Enter Expression: ");
    scanf("%s", exp);

    while (exp[i] != '\0') {
        if (isalnum(exp[i])) {
            printf("%c", exp[i]);
        } 
        else if (exp[i] == '(') {
            push(exp[i]);
        } 
        else if (exp[i] == ')') {
            while ((x = pop()) != '(') {
                printf("%c", x);
            }
        } 
        else {
            // Operator logic
            while (top != -1 && priority(stack[top]) >= priority(exp[i])) {
                printf("%c", pop());
            }
            push(exp[i]);
        }
        i++;
    }

    // Pop remaining operators from the stack
    while (top != -1) {
        printf("%c", pop());
    }
    
    printf("\n");
}