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
    int ch, data, f,n,i;
    queue *q;
    printf("\nEnter no of queues: ");
    scanf("%d",&n);
    q=(queue *)malloc(sizeof(queue)*n);
    for(i=0;i<n;i++)
        init(q+i);
    do
    {
        printf("\n1.Insert into specific queue.\n2.Deque specific queue\n3.Check If specific queue Full\n4.Check If specific queue Empty\n5.Print specific queue\n0.Quit\n: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nIndex[0-%d]: ",n-1);
            scanf("%d",&i);
            printf("\nEnter data to insert: ");
            scanf("%d", &data);
            enqueue(q+i, data);
            //printf("%d", q.data[q.rear]);
            break;
        case 2:
            f = 1;
            printf("\nIndex[0-%d]: ",n-1);
            scanf("%d",&i);
            data = deque(q+i, data, &f);
            if (f)
                printf("\nValue removed: %d", data);
            break;
        case 3:
            printf("\nIndex[0-%d]: ",n-1);
            scanf("%d",&i);
            if (isFull(q+i))
                printf("\nQueue is Full.");
            else
                printf("\nQueue not full.");
            break;
        case 4:
            printf("\nIndex[0-%d]: ",n-1);
            scanf("%d",&i);
            if (isEmpty(q+i))
                printf("\nQueue is Empty.");
            else
                printf("\nQueue not empty.");
            break;
        case 5:
            printf("\nIndex[0-%d]: ",n-1);
            scanf("%d",&i);
            printf("\n");
            print_queue(q+i);
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