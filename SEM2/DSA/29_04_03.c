#include <stdio.h>
#include <stdlib.h>
#define NON -100

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    int l;
    int r;
} node;

node *create(node *p, int i)
{
    node *t, *c;
    int ch;
    if (p == NULL)
    {
        p = (node *)malloc(sizeof(node));
        p->data = NON;
        p->l = 0;
        p->r = 0;
        p->right = p;
        p->left = p;
        p->left = create(p, 0);
        return p;
    }
    else
    {
        t = (node *)malloc(sizeof(node));
        printf("Enter data: ");
        scanf("%d", &t->data);
        t->l = 1;
        t->r = 1;
        if (i == 0)
        {
            t->left = p->left;
            t->right = p;
        }
        else
        {
            t->left = p;
            t->right = p->right;
        }
        printf("\nAdd left child for node with data %d?(1/0): ", t->data);
        scanf("%d", &ch);
        if (ch)
        {
            t->left = create(t, 0);
            t->l = 0;
        }
        printf("\nAdd right child for node with data %d?(1/0): ", t->data);
        scanf("%d", &ch);
        if (ch)
        {
            t->right = create(t, 1);
            t->r = 0;
        }
    }
    return t;
}

void inorder(node *p)
{
    if (p == NULL)
        return;
    node *t = p->left;
    while (t != p)
    {
        while (t->l == 0)
            t = t->left;
        printf("%d ", t->data);
        while (t->r)
        {
            t = t->right;
            if (t == p)
                break;
            printf("%d ", t->data);
        }
        t = t->right;
    }
    return;
}
int main()
{
    node *root = NULL;
    int ch;
    do
    {
        printf("\n1.Create\n2.Inorder\n0.Quit\n-> ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            root = create(root, 0);
            break;
        case 2:
            inorder(root);
            break;
        case 0:
            break;
        default:
            printf("\nIncorrect choice.");
            break;
        }
    } while (ch != 0);

    return 0;
}