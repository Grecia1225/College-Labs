#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *first = NULL, *last = NULL;

// 1. Insert at Beginning
void insertatbeg() {
    struct node *newnode;
    int data;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("circular linked list is overflow\n");
        exit(1);
    }
    printf("Enter data: ");
    scanf("%d", &data);
    newnode->data = data;
    newnode->next = NULL;

    if (first == NULL) {
        first = newnode;
        last = newnode;
        last->next = first;
    } else {
        newnode->next = last->next;
        last->next = newnode;
        first = newnode;
    }
}

// 2. Insert at End
void insertatend() {
    struct node *newnode, *temp;
    int data;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("circular linked list is overflow\n");
        exit(1);
    }
    printf("Enter data: ");
    scanf("%d", &data);
    newnode->data = data;
    newnode->next = NULL;

    if (first == NULL) {
        first = newnode;
        last = newnode;
        last->next = first;
    } else {
        temp = first;
        while (temp->next != last->next) {
            temp = temp->next;
        }
        last->next = newnode;
        last = last->next;
        last->next = first;
    }
}

// 3. Insert at Specific Location
void insertatspecific() {
    struct node *newnode, *temp;
    int data, value;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("circular linked list is overflow\n");
        exit(1);
    }
    printf("Enter data: ");
    scanf("%d", &data);
    printf("Enter value: ");
    scanf("%d", &value);
    newnode->data = data;
    newnode->next = NULL;

    if (first == NULL) {
        first = newnode;
        last = newnode;
        last->next = first;
    } else {
        temp = first;
        while (temp->data != value) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

// 4. Delete at Beginning
void deleteatbeg() {
    struct node *temp;
    int data;
    if (first == NULL) {
        printf("circular linked list is empty\n");
        exit(1);
    }
    temp = first;
    data = temp->data;
    printf("delete data is %d\n", data);
    last->next = temp->next;
    first = first->next;
    free(temp);
    temp = NULL;
}

// 5. Delete at End
void deleteatend() {
    struct node *temp, *temp1;
    int data;
    if (first == NULL) {
        printf("circular linked list is empty\n");
        exit(1);
    }
    temp = first;
    while (temp->next != last->next) {
        temp1 = temp;
        temp = temp->next;
    }
    data = temp->data;
    printf("delete value is %d\n", data);
    temp1->next = first;
    free(temp);
    temp = NULL;
}

// 6. Delete at Specific Location
void deleteatspecific() {
    struct node *temp1, *temp2;
    int data;
    if (first == NULL) {
        printf("circular linked list is empty\n");
        exit(1);
    }
    printf("Enter value to delete at specific position: ");
    scanf("%d", &data);
    temp1 = first;
    while (temp1->data != data) {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    temp2->next = temp1->next;
    free(temp1);
}

// 7. Display
void display() {
    struct node *temp;
    if (first == NULL) {
        printf("The list is empty\n");
        exit(1);
    }
    temp = first;
    while (temp->next != first) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

// Main Function
void main() {
    int choice;
    printf("circular linked list\n");
    while (1) {
        printf("\n1. Insertatbeg\n2. Insertatend\n3. Insertatspecific\n4. Deleteatbeg\n5. Deleteatend\n6. Deleteatspecific\n7. Display\n");
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