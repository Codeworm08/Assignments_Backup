#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

// Create tree
void create_tree(node **p)
{
    *p = NULL;
    printf("Binary Search Tree is created\n");
    return;
}

// Create node
node *create(int n)
{
    node *t = (node *)malloc(sizeof(node));
    t->data = n;
    t->left = NULL;
    t->right = NULL;
    return (t);
}

// Insert iterative
void insert(node **p, int n)
{
    node *c, *t = *p;
    c = create(n);
    if (*p == NULL)
    {
        *p = c;
        return;
    }
    while (t != NULL)
    {
        if (t->data == n)
        {
            printf("No dublicate data\n");
            return;
        }
        else if (t->data < n)
        {
            if (t->right != NULL)
                t = t->right;
            else
            {
                t->right = c;
                return;
            }
        }
        else
        {
            if (t->left != NULL)
                t = t->left;
            else
            {
                t->left = c;
                return;
            }
        }
    }
}

// Search
node *search(node *p, int n)
{
    node *t = p;
    if (p == NULL)
        return (NULL);
    while (t != NULL)
    {
        if (t->data == n)
            return (t);
        if (t->data < n)
            t = t->right;
        else
            t = t->left;
    }
    return (NULL);
}

// Smallest element
node *small(node *p)
{
    node *c = p;
    while (c->left != NULL)
        c = c->left;
    return (c);
}

// delete
node *deletenode(node *p, int n)
{
    node *t;
    if (p == NULL)
        return (p);
    if (p->data < n)
        p->right = deletenode(p->right, n);
    else if (p->data > n)
        p->left = deletenode(p->left, n);
    else
    {
        if (p->left == NULL)
        {
            t = p->right;
            free(p);
            return (t);
        }
        if (p->right == NULL)
        {
            t = p->left;
            free(p);
            return (t);
        }
        t = small(p->right);
        p->data = t->data;
        p->right = deletenode(p->right, t->data);
    }
    return (p);
}

int main()
{
    node *root;
    int choice, n;
    do
    {
        printf("\n\nEnter option :\n");
        printf("0 -> Exit\n1 -> Create Tree\n2 -> Insert\n3 -> Search\n4 -> Delete\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            break;
        case 1:
            create_tree(&root);
            break;
        case 2:
            printf("Enter the data to be inserted = ");
            scanf("%d", &n);
            insert(&root, n);
            break;
        case 3:
            printf("Enter the data to be search = ");
            scanf("%d", &n);
            if (search(root, n))
                printf("Value found\n");
            else
                printf("Value not found");
            break;
        case 4:
            printf("Enter the data to be deleted = ");
            scanf("%d", &n);
            root = deletenode(root, n);
            break;
        default:
            printf("Enter a number between 0 to 12\n");
            break;
        }
    } while (choice != 0);
    return (0);
}
