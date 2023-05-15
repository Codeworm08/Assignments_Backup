#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
struct list
{
    char data;
    struct list *next;
};
typedef struct list *node;

node createNode(char data)
{
    node new = (node)malloc(sizeof(struct list));
    new->data = data;
    new->next = NULL;
    return new;
}

void lpush(char n, node *top)
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
char lpop(node *top, int *f)
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
/*void display(node c)
{
    node t=c;
    printf("\n");
    if(c==NULL)
    {
        return;
    }
    while(t->next!=NULL)
    {
        printf("%d->",t->data);
        t=t->next;
    }
    printf("%d",t->data);
}*/
bool brackBal(char s[])
{
    node check=NULL;
    int i=0,f=1;
    while (s[i]!='\0')
    {
        //display(check);
        if(s[i]=='('||s[i]=='{'||s[i]=='[')
            lpush(s[i],&check);
        else
        {
            if(s[i]==')')
            {
                if(!check || '('!=lpop(&check,&f))
                return false;
            }
            else if(s[i]=='}')
            {
                if(!check || '{'!=lpop(&check,&f))
                return false;
            }
            else if(s[i]==']')
            {
                if(!check || '['!=lpop(&check,&f))
                return false;
            }
        }
        i++;
    }
    if(check==NULL)
        return true;
    return false;
}
int main()
{
    char s[100];
    printf("\nEnter expression with brackets:");
    fgets(s,100,stdin);
    if(brackBal(s)==true)
        printf("\nParentheses valid.");
    else
        printf("\nInvalid placement of parentheses.");
    return 0;
}