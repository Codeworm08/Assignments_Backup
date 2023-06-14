#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
struct list{
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

void lpush(char n,node *top)
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
    char t=(*top)->data;
    *top=(*top)->next;
    p->next=NULL;
    free(p);
    return t;
}
char lpeek(node *top,int *f)
{
    if(*top == NULL)
    {
        *f=0;//flag to check Underflow
        return -1;
    }
    char t=(*top)->data;
    *f=1;
    return t;
}
int precedence(char n)
{
	if(n=='^')
		return 3;
	if(n=='*'||n=='/')
		return 2;
	if(n=='+'||n=='-')
		return 1;
	else
		return 0;
}
bool isEmpty(node *top)
{
    if(*top==NULL)
        return true;
    return false;
}
void postfix(char in[200])
{
    node top=NULL;
    int f=1;
    int i=0;
    char c,p,x;
    while(in[i]!='\0')
    {
        c = tolower(in[i]);
        if(isalnum(c))
        {
            printf("%c",c);
            i++;
            continue;
        }
        if(top == NULL)
        {
            lpush(c, &top);
            i++;
            continue;
        }
        switch (c)
        {
        case '(':
            lpush(c, &top);
            i++;
            break;
        case ')':
            x=lpop(&top,&f);
            while(x!='(' && f!=0)
            {
                printf("%c",x);
                x=lpop(&top,&f);
            }
            i++;
            break;
        default:
            p=lpeek(&top,&f);
            if(p=='(')
            {
                //printf("\n%c,%d,%d\n",c,precedence(c),precedence(p));
            }
            if(precedence(c)>precedence(p) && f!=0)
            {
                lpush(c, &top);
                i++;
            }
            else
            {
                while(precedence(c)<=precedence(p) &&f!=0)
                {
                    x=lpop(&top,&f);
                    printf("%c",x);
                    p=lpeek(&top,&f);
                }
                lpush(c, &top);
                i++;
            }
            break;
        }
    }
    while(!isEmpty(&top))
    {
        x=lpop(&top,&f);
        printf("%c",x);
    }
    printf("\n");
}
int main()
{
    node top=NULL;
    char s[200];
    int f=0;
    int n;
    printf("\nEnter infix expression:");
    fgets(s,200,stdin);
    postfix(s);
    return 0;
}