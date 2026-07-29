#include <stdio.h>
#include <ctype.h>

char postfix[20];
int stack[20];
int top = -1;

void push(float ch) {
    top++;
    stack[top] = ch;
}

int pop() {
    int x;
    x = stack[top];
    top--;
    return x;
}

void main() {
    int a, b, i;
    printf("Enter the Expression: ");
    scanf("%s", postfix);

    for (i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            push(postfix[i] - 48);
        } else {
            b = pop();
            a = pop();
            switch (postfix[i]) {
                case '+':
                    push(a + b);
                    break;
                case '-':
                    push(a - b);
                    break;
                case '*':
                    push(a * b);
                    break;
                case '/':
                    if (b == 0)
                        printf("Divide by zero");
                    else
                        push(a / b);
                    break;
                case '%':
                    push(a % b);
                    break;
                default:
                    printf("Wrong operator");
            }
        }
    }
    printf("\nThe result of Expression %s = %d\n", postfix, stack[top]);
}