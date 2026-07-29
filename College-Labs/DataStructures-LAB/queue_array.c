#include <stdio.h>
#define size 5

void enqueue();
void dequeue();
void display();

int i, front = -1, rear = -1, value;
int queue[size];

void main()
{
    int choice;
    printf("Queue using array");
    printf("\n1. insertion\n2. deletion\n3. display");
    
    while (1)
    {
        printf("\n enter the choice");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            default:
                printf("Wrong choice: please enter again");
        }
    }
}

void enqueue()
{
    if (rear == size - 1)
    {
        printf("queue is overflow");
    }
    else
    {
        printf("enter value");
        scanf("%d", &value);
        
        if (front == -1)
        {
            front = 0;
        }
        
        rear++;
        queue[rear] = value;
    }
}

void dequeue()
{
    if (rear == -1 || front > rear)
    {
        printf("queue is underflow");
    }
    else
    {
        value = queue[front];
        printf("%d is deleted\n", value);
        front++;
    }
}

void display()
{
    printf("queue element are \n");
    
    if (rear == -1)
    {
        printf("queue is empty");
    }
    else
    {
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}