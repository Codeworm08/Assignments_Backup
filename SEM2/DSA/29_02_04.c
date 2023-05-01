#include <stdio.h>
#include <stdlib.h>

/*
    i.) 2d Array
*/
int **createArr(int n)
{
    int **arr = (int **)calloc(sizeof(int *), 2);
    for (int i = 0; i < 2; i++)
        arr[i] = (int *)calloc(sizeof(int), n);
    for (int i = 0; i < n; i++)
        arr[0][i] = i + 1;
    return arr;
}
int left(int **m, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (m[1][i] == 0)
            count++;
    }
    return count;
}
int ex2d(int **p, int n, int k, int st)
{
    int i = st, sk;
    while (left(p, n) > 1)
    {
        while (p[1][i] != 0)
            i = (i + 1) % n;
        sk = 0;
        while (sk <= k)
        {
            if (p[1][i] == 0)
                sk++;
            i = (i + 1) % n;
        }
        //printf("%d",i);
        while (p[1][i] != 0)
            i = (i + 1) % n;
        p[1][i] = 1;
        //printf("%d=>%d",i,p[1][i]);
    }
    for(i =0; i<n;i++)
    {
        if(p[1][i]==0)
            return i;
    }
}

/*
    ii.) Circular Linked List
*/

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

int exL(int n, int k, int st, node *head)
{
    int i;
    node r, prev;
    r = *head;

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
            prev = *head;
            while (prev->next != r)
                prev = prev->next;
            prev->next = r->next;
            r->next = NULL;
            free(r);
            r = prev->next;
        }
    }
    return (*head)->data;
}

/*
    iii.) Circular Doubly Linked List
*/
struct dlist
{
    int data;
    struct dlist *left;
    struct dlist *right;
};
typedef struct dlist *dnode;
dnode createDNode(int i)
{
    dnode temp;
    temp = (dnode)malloc(sizeof(struct dlist));
    temp->data = i;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void createDList(int n, dnode *head)
{
    dnode temp, rear;
    *head = NULL;
    int i;
    for (i = 0; i < n; i++)
    {
        temp = createDNode(i);
        if (*head == NULL)
        {
            *head = temp;
            rear = *head;
            rear->right = *head;
            rear->left = *head;
        }
        else
        {
            rear->right = temp;
            temp->left = rear;
            rear = rear->right;
            rear->right = *head;
            (*head)->left = rear;
        }
    }
}
int exDL(int n, int k, int st, dnode *head)
{
    int i;
    dnode r, prev;
    r = *head;
    for (i = 0; i < st; i++)
        r = r->right;
    while ((*head)->right != *head)
    {
        for (i = 0; i <= k; i++)
            r = r->right;
        if (r == *head)
        {
            prev = (*head)->left;
            (*head) = (*head)->right;
            prev->right = (*head);
            (*head)->left = prev;
            r->left = NULL;
            r->right = NULL;
            free(r);
            r = *head;
        }
        else if (r->right == *head)
        {
            prev = r->left;
            prev->right = *head;
            (*head)->left = prev;
            r->right = NULL;
            r->left = NULL;
            free(r);
            r = *head;
        }
        else
        {
            prev = r->left;
            prev->right = r->right;
            r->right->left = prev;
            r->left = NULL;
            r->right = NULL;
            free(r);
            r = prev->right;
        }
    }
    return (*head)->data;
}
int main()
{
    node head;
    dnode dhead;
    int n, k, st, ch;
    int **p;
    do
    {
        printf("\nEnter no of people: ");
        scanf("%d", &n);
        printf("\nEnter skips: ");
        scanf("%d", &k);
        printf("\nEnter starting point(0-%d): ", n - 1);
        scanf("%d", &st);
        printf("\n1->2d Array\n2->Circular Linked List\n3->Circular Doubly Linked List\n0->Quit\n\t=>");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            p = createArr(n);
            printf("\nPerson alive: %d\n", ex2d(p, n, k, st));
            break;
        case 2:
            createList(n, &head);
            printf("\nPerson alive: %d\n", exL(n, k, st, &head));
            break;
        case 3:
            createDList(n, &dhead);
            printf("\nPerson alive: %d\n", exDL(n, k, st, &dhead));
            break;
        case 0:
            break;
        default:
            printf("\nInvalid choice.");
        }
    } while (ch != 0);
    return 0;
}