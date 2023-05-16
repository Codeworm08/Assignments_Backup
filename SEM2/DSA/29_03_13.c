#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 10
struct list{
    int data;
    struct list *next;
};
typedef struct list *node;

node createNode(int data)
{
    node new = (node)malloc(sizeof(struct list));
    new->data = data;
    new->next = NULL;
    return new;
}

void lpush(int n,node *top)
{
    node p;
    if(*top == NULL)
    {
        *top=createNode(n);
        return;
    }
    p=createNode(n);
    p->next=*top;
    *top=p;
}
int lpop(node *top,int *f)
{
    if(*top == NULL)
    {
        *f=-1;//flag to check Underflow
        return -1;
    }
    node p=*top;
    int t=(*top)->data;
    *top=(*top)->next;
    p->next=NULL;
    free(p);
    return t;
}
int lpeek(node *top,int *f)
{
    if(*top == NULL)
    {
        *f=0;//flag to check Underflow
        return -1;
    }
    int t=(*top)->data;
    *f=1;
    return t;
}
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
void reverse(queue *q)
{
    if(isEmpty(q))
    {
        printf("\nQueue is empty.\n");
        return;
    }
    node top=NULL;
    int f=1;
    while(!isEmpty(q))
    {
        f=1;
        lpush(deque(q,&f),&top);
    }
    while(top!=NULL){
        f=1;
        enqueue(q,lpop(&top,&f));
    }
    printf("\nReverse:\n");
    print_queue(q);
}
int main()
{
    int ch, data, f;
    queue q;
    init(&q);
    printf("\nEnter queue:");
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
    print_queue(&q);
    reverse(&q);
    return 0;
}