#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
struct list
{
    float data;
    struct list *next;
};
typedef struct list *node;

node createNode(float data)
{
    node new = (node)malloc(sizeof(struct list));
    new->data = data;
    new->next = NULL;
    return new;
}

void lpush(float n, node *top)
{
    node p;
    if (*top == NULL)
    {
        *top = createNode(n);
        return;
    }
    p = createNode(n);
    p->next = *top;
    *top = p;
}
float lpop(node *top, int *f)
{
    if (*top == NULL)
    {
        *f = 0; // flag to check Underflow
        return -1;
    }
    node p = *top;
    int t = (*top)->data;
    *top = (*top)->next;
    p->next = NULL;
    free(p);
    return t;
}

float lpeek(node *top, int *f)
{
    if (*top == NULL)
    {
        *f = 0; // flag to check Underflow
        return -1;
    }
    return (*top)->data;
}
float postfixEval(char s[])
{
    node ex = NULL;
    int i = 0, f = 1;
    float res = 0, x = 0, y = 0;
    while (s[i] != '\0')
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            lpush(s[i] - '0', &ex);
            i++;
        }
        else
        {
            f = 1;
            x = lpop(&ex, &f);
            f = 1;
            y = lpop(&ex, &f);
            switch (s[i])
            {
            case '+':
                res = x + y;
                break;
            case '-':
                res = y - x;
                break;
            case '*':
                res = y * x;
                break;
            case '/':
                res = y / x;
                break;
            }
            lpush(res, &ex);
            i++;
        }
    }
    f = 1;
    return lpop(&ex, &f);
}
int main()
{
    char post[50];
    printf("Enter the postfix expression :\n");
    fgets(post, 50, stdin);
    printf("Evaluated value = %f\n", postfixEval(post));
    return (0);
}