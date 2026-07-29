#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *head = NULL;

// 1. Insert at Beginning
void insertatbeg() {
    struct node *newnode;
    int data;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory full\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &data);
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

// 2. Insert at End
void insertatend() {
    struct node *newnode, *temp;
    int data;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &data);
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// 3. Insert at Specific Location (After a value)
void insertatspecific() {
    struct node *newnode, *temp;
    int data, val;
    printf("Enter data to insert: ");
    scanf("%d", &data);
    printf("Enter value after which to insert: ");
    scanf("%d", &val);

    temp = head;
    while (temp != NULL && temp->data != val) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found\n");
    } else {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

// 4. Delete at Beginning
void deleteatbeg() {
    struct node *temp;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = head;
    head = head->next;
    printf("Deleted: %d\n", temp->data);
    free(temp);
}

// 5. Delete at End
void deleteatend() {
    struct node *temp, *prev;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = head;
    if (temp->next == NULL) {
        head = NULL;
    } else {
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
    }
    printf("Deleted: %d\n", temp->data);
    free(temp);
}

// 6. Display
void display() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main Function
void main() {
    int choice;
    while (1) {
        printf("\n1. Insert Beg\n2. Insert End\n3. Insert Specific\n4. Delete Beg\n5. Delete End\n6. Display\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insertatbeg(); break;
            case 2: insertatend(); break;
            case 3: insertatspecific(); break;
            case 4: deleteatbeg(); break;
            case 5: deleteatend(); break;
            case 6: display(); break;
            case 7: exit(0);
            default: printf("Invalid Choice\n");
        }
    }
}