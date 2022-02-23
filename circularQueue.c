#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int rear = -1, front = -1;
int q[4] = {0, 0, 0, 0};// circular queue using arrays of size 4

void Enqueue()
{
    int item;
    printf("enter item:\t");
    scanf("%d", &item);
    rear = (rear + 1) % 4; //incrementing rear index
    if (front == rear)
    {
        printf("Queue is full"); //reverting index incrementation in line 13
        if (rear == 0)
            rear = 4 - 1;
        else
            rear = rear - 1;
        return;
    }
    else
    {
        q[rear] = item;
        if(rear==0){// when first element is entered
            front=0;
        }
        return;
    }
}
void Dequeue()
{
    int k = 0;
    if (front == rear)
    {
        printf("Queue is empty");
    }
    else
    {
        front = (front + 1) % 4; //shifting front
        k = q[front-1];
        q[front-1]=0;
        printf("\nDequeued element:\t %d", k);
    }
    
}

void printQ()
{
    printf("array Q is:\t");
    for (int i = 0; i < 4; i++)
        printf(" %d", q[i]);
    return;
}

void main()
{
    int c = 0;
    while (c != 5)
    {
        printf("\nenter choice:\n1)Enqueue\n2)Dequeue\n3)Print Queue\n5)exit\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            Enqueue();
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            printQ();
            break;
        case 5:
            break;
        default:
            printf("\nInvalid Entry");
            break;
        }
    }
}