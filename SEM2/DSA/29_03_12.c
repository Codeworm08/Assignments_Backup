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
int deque(queue *q, int *f)
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
bool equal(queue p, queue q)
{
    int x,y,f1,f2;
    while(!isEmpty(&p) && !isEmpty(&q))
    {
        f1=1;f2=1;
        x=deque(&p,&f1);
        y=deque(&q,&f2);
        if(f1!=f2 || x!=y)
           return false;
    }
    if(!isEmpty(&p) || !isEmpty(&q))
        return false;
    return true;
}
int main()
{
    int ch, data, f;
    queue q,p;
    init(&q);
    init(&p);
    printf("\nEnter 1st queue:");
    do
    {
        printf("\nEnter data:");
        scanf("%d",&data);
        enqueue(&q,data);
        if(isFull(&q))
        {
            printf("\nQueue is full. Can't add more");
            break;
        }
        printf("\nEnter 0 to quit. Any other number to continue.");
        scanf("%d",&ch);
    } while (ch!=0);
    printf("\nEnter 2nd queue:");
    do
    {
        printf("Enter data:");
        scanf("%d",&data);
        enqueue(&p,data);
        if(isFull(&p))
        {
            printf("\nQueue is full. Can't add more");
            break;
        }
        printf("\nEnter 0 to quit. Any other number to continue.");
        scanf("%d",&ch);
    } while (ch!=0);
    printf("\nFirst queue:\n");
    print_queue(&q);
    printf("\nSecond queue:\n");
    print_queue(&p);
    if(equal(q,p))
    {
        printf("\nQueues are equal");
    }
    else
    {
        printf("\nQueues are not equal");
    }
    return 0;
}