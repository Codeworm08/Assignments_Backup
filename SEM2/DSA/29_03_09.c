#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 10
typedef struct queue
{
    int rear;
    int front;
    int data[MAX_SIZE];
} queue;

void init(queue *q)
{
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(queue *q)
{
    if (q->front == q->rear)
        return true;
    return false;
}

bool isFull(queue *q)
{
    if (q->rear == MAX_SIZE - 1)
        return true;
    return false;
}

void enqueue(queue *q, int data)
{
    if (isFull(q))
    {
        printf("\nQueue is full.");
        return;
    }
    q->rear = q->rear + 1;
    q->data[q->rear] = data;
}
int deque(queue *q, int data, int *f)
{
    if (isEmpty(q))
    {
        printf("\nQueue is empty.");
        *f = 0;
        return -1;
    }
    q->front = q->front + 1;
    return q->data[q->front];
}
void print_queue(queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }

    for (int i = q->front + 1; i <= q->rear; i++)
    {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main()
{
    int ch, data, f;
    queue q;
    init(&q);
    do
    {
        printf("\n1.Insert into queue.\n2.Deque\n3.Check If Full\n4.Check If Empty\n5.Print\n0.Quit\n: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter data to insert: ");
            scanf("%d", &data);
            enqueue(&q, data);
            printf("%d", q.data[q.rear]);
            break;
        case 2:
            f = 1;
            data = deque(&q, data, &f);
            if (f)
                printf("\nValue removed: %d", data);
            break;
        case 3:
            if (isFull(&q))
                printf("\nQueue is Full.");
            else
                printf("\nQueue not full.");
            break;
        case 4:
            if (isEmpty(&q))
                printf("\nQueue is Empty.");
            else
                printf("\nQueue not empty.");
            break;
        case 5:
            printf("\n");
            print_queue(&q);
            break;
        case 0:
            break;
        default:
            printf("\nInvalid Input.");
            break;
        }
    } while (ch != 0);

    return 0;
}