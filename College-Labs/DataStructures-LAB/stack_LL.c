#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *top = NULL;

void push() {
    struct node *newnode;
    int data;
    
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\nStack is overflow\n");
        exit(1);
    }
    
    printf("\nEnter data to push: ");
    scanf("%d", &data);
    
    newnode->data = data;
    newnode->next = top;
    top = newnode;
}

int pop() {
    struct node *temp;
    int value;
    
    if (top == NULL) {
        printf("\nStack is underflow\n");
        exit(1);
    }
    
    temp = top;
    value = temp->data;
    top = top->next;
    free(temp);
    temp = NULL;
    return value;
}

void display() {
    struct node *temp;
    temp = top;
    
    if (top == NULL) {
        printf("\nStack underflow\n");
        return; // Changed exit to return so the program keeps running
    }
    
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data;
    
    printf("\nImplementation of stack using linked list\n");
    
    while (1) {
        printf("\n1. Push \n2. POP \n3. Display \n4. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                data = pop();
                printf("Popped element is: %d\n", data);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong choice \n");
        }
    }
    return 0;
}