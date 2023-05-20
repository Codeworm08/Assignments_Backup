#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *queue;
int front = -1;
int rear = -1;
int max_size;
void size()
{
    printf("\nEnter the maximum size of the queue: ");
    scanf("%d", &max_size);
    queue = (int *)malloc(sizeof(int) * max_size);
}
bool enqueue(int data)
{
    if (front == 0 && rear == max_size - 1)
    {
        printf("\nOverflow");
        return false;
    }
    if (front == rear && front == -1)
    {
        front = rear = 0;
    }
    else
        rear = (rear + 1) % max_size;
    queue[rear] = data;
    return true;
}
bool dequeue(int *x)
{
    if (front == -1)
    {
        printf("\nUnderflow");
        return false;
    }
    *x = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % max_size;
    return true;
}
bool getFront(int *x)
{

    if (front == -1)
    {
        printf("\nUnderflow");
        return false;
    }
    *x = queue[front];
    return true;
}

int main()
{
    int ch,data;
    size();
    do{
        printf("\n0->Quit\n1->Enqueue\n2->Dequeue\n3->Get Front\n=> ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 0:
            break;
        case 1:
            printf("\nEnter data: ");
            scanf("%d",&data);
            enqueue(data);
            break;
        case 2:
            if(dequeue(&data))
            {
                printf("\nData popped: %d",data);
            }
            break;
        case 3:
            if(getFront(&data))
                printf("\nData at queue front: %d",data);
            break;
        default:
            printf("\nInvalid input.");
            break;
        }
    }while(ch!=0);
    return 0;
}
