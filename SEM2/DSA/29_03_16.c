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

    return 0;
}