#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
} *first = NULL, *last = NULL;

// 1. Insert at Beginning
void insertatbeg() {
    struct node *newnode;
    int data;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory is full\n");
        exit(1);
    }
    printf("Enter data: ");
    scanf("%d", &data);
    newnode->prev = NULL;
    newnode->data = data;
    newnode->next = NULL;

    if (first == NULL) {
        first = newnode;
        last = newnode;
        last->next = newnode;
        first->prev = newnode;
    } else {
        newnode->next = first;
        first->prev = newnode;
        first = newnode;
        last->next = first;
        first->prev = last;
    }
}

// 2. Insert at End
void insertatend() {
    struct node *newnode, *temp;
    int data;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory is full\n");
        exit(1);
    }
    printf("Enter data: ");
    scanf("%d", &data);
    newnode->prev = NULL;
    newnode->data = data;
    newnode->next = NULL;

    if (first == NULL) {
        first = newnode;
        last = newnode;
        last->next = newnode;
        first->prev = newnode;
    } else {
        temp = first;
        while (temp->next != last->next) {
            temp = temp->next;
        }
        last->next = newnode;
        newnode->prev = last;
        last = newnode;
        last->next = first;
        first->prev = last;
    }
}

// 3. Insert at Specific Location
void insertatspecific() {
    struct node *newnode, *temp;
    int value1, value2;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Circular doubly linked list is overflow\n");
        exit(1);
    }
    printf("Enter value 1: ");
    scanf("%d", &value1);
    printf("Enter value 2 (after which to insert): ");
    scanf("%d", &value2);
    
    newnode->prev = NULL;
    newnode->data = value1;
    newnode->next = NULL;

    if (first == NULL) {
        first = newnode;
        last = newnode;
        last->next = newnode;
    } else {
        temp = first;
        while (temp->data != value2) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;
        newnode->prev = temp;
    }
}

// 4. Delete at Beginning
void deleteatbeg() {
    struct node *temp;
    if (first == NULL) {
        printf("Circular doubly linked list is empty\n");
        exit(1);
    }
    temp = first;
    first = first->next;
    temp->next = NULL;
    temp->prev = NULL;
    last->next = first;
    first->prev = last;
    free(temp);
    temp = NULL;
}

// 5. Delete at End
void deleteatend() {
    struct node *temp;
    if (first == NULL) {
        printf("Circular doubly linked list is empty\n");
        exit(1);
    }
    temp = first;
    while (temp->next != last->next) {
        temp = temp->next;
    }
    last = last->prev;
    last->next = first;
    first->prev = last;
    temp->prev = NULL;
    temp->next = NULL;
    free(temp);
    temp = NULL;
}

// 6. Delete at Specific Location
void deleteatspecific() {
    struct node *temp;
    int value;
    if (first == NULL) {
        printf("Circular linked list is empty\n");
        exit(1);
    }
    printf("Enter value to delete: ");
    scanf("%d", &value);
    temp = first;
    while (temp->data != value) {
        temp = temp->next;
    }
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    free(temp);
}

// 7. Display
void display() {
    struct node *temp;
    if (first == NULL) {
        printf("Circular doubly linked list is empty\n");
        exit(1);
    }
    temp = first;
    while (temp->next != last->next) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

// Main Function
void main() {
    int choice;
    printf("Circular doubly linked list\n");
    while (1) {
        printf("\n1. Insertatbeg\n2. Insertatend\n3. Insertat specific\n4. Delete at beg\n5. Delete at end\n6. Delete at specific\n7. Display\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertatbeg(); break;
            case 2: insertatend(); break;
            case 3: insertatspecific(); break;
            case 4: deleteatbeg(); break;
            case 5: deleteatend(); break;
            case 6: deleteatspecific(); break;
            case 7: display(); break;
            default:
                printf("Wrong Choice\n");
                break;
        }
    }
}