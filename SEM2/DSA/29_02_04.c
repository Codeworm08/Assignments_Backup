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
        temp = createNode(i);
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

void delFirst(node *head)
{
    node p, t;
    if (*head == NULL)
    {
        printf("\nEmpty List!!");
        return;
    }
    p = *head;
    t = *head;
    while (t->next != *head)
        t = t->next;
    if (t == *head)
    {
        *head = NULL;
        free(t);
    }
    // printf("\nElement deleted: %d",head->data);
    *head = (*head)->next;
    free(p);
}

void delK(int k, node *head)
{
    node p, t;
    int i;
    if (*head == NULL)
    {
        printf("\nEmpty List!!");
        return;
    }
    if (k == 1)
    {
        delFirst(head);
        return;
    }
    p = *head;
    for (i = 1; i < k - 1; i++)
    {
        if (p->next == *head)
        {
            printf("\nPosition does not exist in List!");
            return;
        }
        p = p->next;
    }
    t = p->next;
    p->next = t->next;
    t->next = NULL;
    free(t);
}

int exL(int n, int k, node *head)
{
    int i, st;
    node r, prev;
    r = *head;
    printf("\nEnter starting point(0-%d): ", n - 1);
    scanf("%d", &st);
    for (i = 0; i < st; i++)
        r = r->next;
    while ((*head)->next != *head)
    {
        for (i = 0; i <= k; i++)
            r = r->next;
        if (r == *head)
        {
            prev = *head;
            while (prev->next != *head)
                prev = prev->next;
            *head = (*head)->next;
            prev->next = *head;
            r->next = NULL;
            free(r);
            r = *head;
        }
        else if (r->next == *head)
        {
            prev = *head;
            while (prev->next != r)
                prev = prev->next;
            prev->next = *head;
            r->next = NULL;
            free(r);
            r = *head;
        }
        else
        {
            prev->next = r->next;
            r->next = NULL;
            free(r);
            r = prev->next;
        }
    }
    return (*head)->data;
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
    printf("\nPerson alive: %d\n", exL(n, k, &head));
    // printf("\n%d", ex2d(n, k));
    return 0;
}