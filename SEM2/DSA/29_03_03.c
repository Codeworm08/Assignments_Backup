#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 4
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
void reverse(FILE *fp)
{
    node top=NULL;
    char ch;
    printf("\nOrder in file=");
    while(!feof(fp))
    {
        ch=fgetc(fp);
        printf("%c ",ch);
        if(ch>='0' &&ch <='9')
            lpush(ch-'0',&top);
    }
    printf("\nRverse=");
    int f=1;
    while(top)
    {
        printf("%d",lpop(&top,&f));
    }
}
int main()
{
    FILE *fp;
    fp=fopen("integers.txt","r");
    if(fp==NULL)
    {
        printf("\nFile does not exist!");
        exit(0);
    }
    reverse(fp);
    fclose(fp);
    return 0;
}