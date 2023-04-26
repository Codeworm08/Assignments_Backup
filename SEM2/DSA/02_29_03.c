#include <stdio.h>
#include <stdlib.h>
struct list
{
    int data;
    struct list *right;
    struct list *left;
};

typedef struct list *node;

node head = NULL;
node b = NULL;

void createNode(int data, node *temp)
{
    node r, t;
    r = (node)malloc(sizeof(struct list));
    r->left = NULL;
    r->right = NULL;
    r->data = data;

    if (*temp == NULL)
    {
        *temp = r;
    }
    else
    {
        t = *temp;
        while (t->right != NULL)
            t = t->right;
        t->right = r;
        r->left = t;
    }
}
void createList(node *head)
{
    int data, x;
    if (*head != NULL)
    {
        printf("\nList already exists!");
        return;
    }
    do
    {
        printf("\nEnter data: ");
        scanf("%d", &data);
        createNode(data, head);
        printf("\nEnter 0 to Stop.");
        scanf("%d", &x);
    } while (x != 0);
}

void display(node head)
{
    node t;
    if (head == NULL)
    {
        return;
    }
    t = head;
    printf("\n");
    while (t->right != NULL)
    {
        printf("%d<=>", t->data);
        t = t->right;
    }
    printf("%d\n", t->data); /* constant-expression */
                             /* code */
}
void insertFront(node *head)
{
    int data;
    node t, h;
    printf("\nEnter data: ");
    scanf("%d", &data);
    t = (node)malloc(sizeof(struct list));
    t->data = data;
    t->right = NULL;
    t->left = NULL;
    if (*head == NULL)
    {
        *head = t;
        return;
    }
    h = *head;
    t->right = h;
    h->left = t;
    *head = t;
}
void insertEnd(node *head)
{
    int data;
    node t, x;
    printf("\nEnter data: ");
    scanf("%d", &data);
    t = (node)malloc(sizeof(struct list));
    t->data = data;
    t->right = NULL;
    t->left = NULL;
    if (*head == NULL)
    {
        *head = t;
        return;
    }
    x = *head;
    while (x->right != NULL)
        x = x->right;
    x->right = t;
    t->left = x;
}

void insertAftK(node *head, int k)
{
    int data, i;
    node t, x;
    if (*head == NULL || k < 1)
    {
        printf("\nPosition %d does not exist in List.", k);
        return;
    }
    x = *head;
    for (i = 1; i < k; i++)
    {
        if (x == NULL)
        {
            printf("\nPosition %d exceeds List", k);
            return;
        }
        x = x->right;
    }
    printf("\nEnter data: ");
    scanf("%d", &data);
    t = (node)malloc(sizeof(struct list));
    t->data = data;
    t->right = NULL;
    t->left = NULL;

    if (x->right == NULL)
    {
        x->right = t;
        t->left = x;
        return;
    }
    t->right = x->right;
    x->right->left = t;
    t->left = x;
    x->right = t;
}

void insertAftVal(node head, int val)
{
    node t, x;
    int data, i;
    if (head == NULL)
    {
        printf("\nList empty!!");
        return;
    }
    x = head;
    while (x->data != val)
    {
        if (x->right == NULL)
        {
            printf("\nValue %d not found in List", val);
            return;
        }
        x = x->right;
    }
    printf("\nEnter data: ");
    scanf("%d", &data);
    t = (node)malloc(sizeof(struct list));
    t->data = data;
    t->right = NULL;
    t->left = NULL;
    if (x->right == NULL)
    {
        x->right = t;
        t->left = x;
        return;
    }
    t->right = x->right;
    x->right->left = t;
    t->left = x;
    x->right = t;
}

void insertBefK(node *head, int k)
{
    k--;
    if (k < 0)
    {
        printf("\nCan't insert before beginning of list!");
        return;
    }
    if (k == 0)
    {
        insertFront(head);
        return;
    }
    insertAftK(head, k);
}
void insertBefVal(node *head, int val)
{
    node t, x;
    int data, i;
    if (*head == NULL)
    {
        printf("\nList empty!!");
        return;
    }
    x = *head;
    while (x->data != val)
    {
        if (x->right == NULL)
        {
            printf("\nValue %d not found in List", val);
            return;
        }
        x = x->right;
    }
    printf("\nEnter data: ");
    scanf("%d", &data);
    t = (node)malloc(sizeof(struct list));
    t->data = data;
    t->right = NULL;
    t->left = NULL;
    if (x->left == NULL)
    {
        t->right = x;
        x->left = t;
        *head = t;
        return;
    }
    t->left = x->left;
    x->left->right = t;
    t->right = x;
    x->left = t;
}

void delFirst(node *head)
{
    node x;
    if (*head == NULL)
    {
        printf("\nList Empty!");
        return;
    }
    x = *head;
    printf("\nElement popped: %d", x->data);
    *head = x->right;
    if (*head == NULL)
    {
        free(x);
        return;
    }
    x->right = NULL;
    (*head)->left = NULL;
    free(x);
}

void delEnd(node *head)
{
    node x;
    if (*head == NULL)
    {
        printf("\nList Empty!");
        return;
    }
    x = *head;
    while (x->right != NULL)
        x = x->right;
    printf("\nElement popped: %d", x->data);
    if (x->left == NULL)
    {
        *head = NULL;
        free(x);
        return;
    }
    x->left->right = NULL;
    x->left = NULL;
    free(x);
}

void delAftK(node *head, int k)
{
    node x, t;
    int i;
    if (*head == NULL || k <= 0)
    {
        printf("\nPosition %d not in List!", k);
        return;
    }
    x = *head;
    for (i = 1; i < k; i++)
    {
        if (x == NULL)
        {
            printf("\nPosition %d exceeds List", k + 1);
            return;
        }
        x = x->right;
    }

    if (x->right == NULL)
    {
        printf("\nReached End Of List!!");
        return;
    }
    t = x->right;
    printf("\nValue deleted: %d", t->data);
    if (t->right == NULL)
        x->right = NULL;
    else
    {
        x->right = t->right;
        t->right->left = x;
    }
    t->right = NULL;
    t->left = NULL;
    free(t);
}

void delBefK(node *head, int k)
{

    if (*head == NULL)
    {
        printf("\nList Empty!!");
        return;
    }
    k -= 2;
    if (k < 0)
    {
        printf("\nNode position begins from 1.");
        return;
    }
    if (k == 0)
    {
        delFirst(head);
        return;
    }
    delAftK(head, k);
}

void delK(node *head, int k)
{
    if (*head == NULL)
    {
        printf("\nList Empty!!");
        return;
    }
    k--;
    if (k == 0)
    {
        delFirst(head);
        return;
    }
    if (k < 0)
    {
        printf("\nNode position begins from 1.");
        return;
    }
    delAftK(head, k);
}

void delVal(node *head, int val)
{
    node x;
    if (*head == NULL)
    {
        printf("\nList Empty!!");
        return;
    }
    x = *head;
    while (x->data != val)
    {
        if (x->right == NULL)
        {
            printf("\nValue not found in List.");
            return;
        }
        x = x->right;
    }
    if (x->right == NULL)
    {
        delEnd(head);
        return;
    }
    if (x->left == NULL)
    {
        delFirst(head);
        return;
    }
    printf("\nValue deleted.");
    x->left->right = x->right;
    x->right->left = x->left;
    x->right = NULL;
    x->left = NULL;
    free(x);
}

void reverse(node *head)
{
    node t, x;
    t = NULL;
    x = *head;
    while (x != NULL)
    {
        t = x->left;
        x->left = x->right;
        x->right = t;
        x = x->left;
    }
    if (t != NULL)
        *head = t->left;
}

int main()
{
    int ch, val, k;
    node head = NULL;
    do
    {
        printf("\n\n1->create List\n2->display\n3->insertFront\n4->insertEnd\n5->insertAfterK");
        printf("\n6->InsertAfterValue\n7->insertBeforeK\n8->insertBeforeValue\n9->deleteFirst\n10->deleteEnd");
        printf("\n11->deleteAfterKthNode\n12->deleteBeforeKthNode\n13->deleteKthNode\n14->deleteNodeWithValue");
        printf("\n15->reverseList\n0->exit\n->");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            createList(&head);
            break;
        case 2:
            display(head);
            break;
        case 3:
            insertFront(&head);
            break;
        case 4:
            insertEnd(&head);
            break;
        case 5:
            printf("\nEnter kth node after which to insert: ");
            scanf("%d", &k);
            insertAftK(&head, k);
            break;
        case 6:
            printf("\nEnter value after which to insert :");
            scanf("%d", &val);
            insertAftVal(head, val);
            break;
        case 7:
            printf("\nEnter kth node before which to insert: ");
            scanf("%d", &k);
            insertBefK(&head, k);
            break;
        case 8:
            printf("\nEnter value before which to insert :");
            scanf("%d", &val);
            insertBefVal(&head, val);
            break;
        case 9:
            delFirst(&head);
            break;
        case 10:
            delEnd(&head);
            break;
        case 11:
            printf("\nEnter position after which to delete: ");
            scanf("%d", &k);
            delAftK(&head, k);
            break;
        case 12:
            printf("\nEnter position before which to delete: ");
            scanf("%d", &k);
            delBefK(&head, k);
            break;
        case 13:
            printf("\nEnter position to be deleted: ");
            scanf("%d", &k);
            delK(&head, k);
            break;
        case 14:
            printf("\nEnter value to be deleted: ");
            scanf("%d", &val);
            delVal(&head, val);
            break;
        case 15:
            printf("\nList Reversed!");
            reverse(&head);
            break;
        case 0:
            break;
        default:
            printf("\nInvalid input!");
            break;
        }
    } while (ch);

    return 0;
}
