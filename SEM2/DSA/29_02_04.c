#include <stdio.h>
#include <stdlib.h>
int ex2d(int n, int k)
{
    int people[n][2];
    for (int i = 0; i < n; i++)
    {
        people[i][0] = i;
        people[i][1] = 0;
    }
    int current = 0;
    while (1)
    {
        int count = people[current][1]; // number of people to skip
        for (int i = 0; i < n; i++)
        {
            if (people[i][1] == 0)
            {
                count--;
                if (count == 0)
                {
                    // execute the next person
                    people[i][1] = 1;
                    current = (i + 1) % n;
                    break;
                }
            }
        }
        int left = 0;
        for (int i = 0; i < n; i++)
        {
            if (people[i][1] == 0)
                left++;
        }
        if (left == 1)
            break;
        people[current][1] = k;
    }
    for (int i = 0; i < n; i++)
    {
        if (people[i][1] == 0)
        {
            return i;
        }
    }
    return 0;
}

struct list
{
    int data;
    struct list *next;
};

typedef struct list *node;

node createNode(int i)
{
    node temp;
    temp = (node)malloc(sizeof(struct list));
    temp->data = i;
    temp->next = NULL;
    return temp;
}
void createList(int n, node *head)
{
    node rear, temp;
    int i;
    *head = NULL;
    for (i = 0; i < n; i++)
    {
        // printf("s");
        temp = createNode(0);
        if (*head == NULL)
        {
            *head = temp;
            rear = *head;
            rear->next = *head;
        }
        else
        {

            rear->next = temp;
            rear = rear->next;
            rear->next = *head;
        }
    }
}
void display(node head)
{
    node t;
    t = head;
    while (t->next != head)
    {
        printf("%d ->", t->data);
        t = t->next;
    }
    printf("%d", t->data);
}
int left(node head)
{
    int l;
    node t;
    t = head;
    l = 0;
    do
    {
        if (t->data == 0)
            l++;
        t = t->next;
    } while (t->next != head);
    return l;
}
int exL(int n, int k, node head)
{
    int i, l;
    node r;
    r = head;
    for (i = 0; i < k - 1; i++)
        r = r->next;
    r->data = 1;
    l = left(head);
    if (l == 1)
    {
        r = head;
        for (i = 0; i < n; i++)
        {
            if (r->data == 0)
                return i;
            r = r->next;
        }
    }
}
int main()
{
    node head;
    int n, k;
    printf("\nEnter no of people: ");
    scanf("%d", &n);
    printf("\nEnter skips: ");
    scanf("%d", &k);
    createList(n, &head);
    display(head);
    printf("\nPerson alive: %d\n",exL(n,k,head));
    // printf("\n%d", ex2d(n, k));
    return 0;
}