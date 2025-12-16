#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert(int item)
{
    if ((rear + 1) % MAX == front)
    {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)   
    {
        front = 0;
    }

    rear = (rear + 1) % MAX;
    queue[rear] = item;

    printf("Element %d inserted\n", item);
}

void delete()
{
    int item;

    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }

    item = queue[front];

    if (front == rear)   
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }

    printf("Deleted element is %d\n", item);
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    int i = front;
    printf("Queue elements: ");

    while (i != rear)
    {
        printf("%d\t", queue[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", queue[rear]);
}

int main()
{
    int ch, item;

    while (1)
    {
        printf("\n***** Circular Queue *****");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);   

        switch (ch)
        {
            case 1:
                printf("Enter item to insert: ");
                scanf("%d", &item);
                insert(item);
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}
