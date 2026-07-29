#include <stdio.h>
#include <stdlib.h>

void push(void);
void pop(void);
void display(void);

int stack[50], size, top = -1, i, value;

int main() {
    int choice;
    printf("Enter size of stack: ");
    scanf("%d", &size);

    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            default:
                printf("\nPlease enter valid choice");
        }
    }
    return 0;
}

void push() {
    if (top >= size - 1) {
        printf("\nStack is overflow");
    } else {
        printf("Enter the value to be pushed: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
    }
}

void pop() {
    if (top <= -1) {
        printf("\nStack is underflow");
    } else {
        printf("The popped element is %d", stack[top]);
        top--;
    }
}

void display() {
    if (top >= 0) {
        printf("\nThe elements in stack:");
        for (i = top; i >= 0; i--) {
            printf("\n%d", stack[i]);
        }
    } else {
        printf("\nStack is empty");
    }
}