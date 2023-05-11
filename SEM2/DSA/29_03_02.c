#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int *a;
    int top;
    int size;
} sta;

void create(sta *st,int size)
{
    st->a = (int *)malloc(sizeof(int) * size);
    st->top = -1;
    st->size = size;
}
void push(sta *st, int data)
{
    if (st->top == st->size - 1)
    {
        printf("\nOverflow!!");
        return;
    }
    st->a[++st->top] = data;
}
int pop(sta *st, int *flag)
{
    int x;
    if (st->top == -1)
    {
        *flag = 0;
        return -1;
    }
    x=st->a[st->top];
    st->top--;
    return x;
}
int peek(sta st,int *flag)
{
    if (st.top == -1)
    {
        *flag = 0;
        return -1;
    }
    return st.a[st.top];
}
int main()
{
    sta * s;
    int ch,n,count=0,size,d,f;
    n=10;
    s=(sta *)malloc(sizeof(sta));
    do
    {
        printf("\n0.Exit");
        printf("\n1.Create new stack");
        printf("\n2.Push to specific stack");
        printf("\n3.Pop from specific stack");
        printf("\n4.Peek specific stack");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter maximum size of linked list: ");
                scanf("%d",&size);
                create(s+count,size);
                count++;
 				s=(sta *)realloc(s,(count+1)*sizeof(sta));
                break;
            case 2:
                printf("\nPossible stack indices:[0-%d]",count-1);
                printf("\nEnter stack index: ");
                scanf("%d",&n);
                while(n>=count || n<0)
                {
                    printf("\nPossible stack indices:[0-%d]",count-1);
                    printf("\nEnter stack index: ");
                    scanf("%d",&n);
                }
                printf("\nEnter element to be pushed: ");
                scanf("%d",&d);
                push(s+n,d);
                break;
            case 3:
                printf("\nPossible stack indices:[0-%d]",count-1);
                printf("\nEnter stack index: ");
                scanf("%d",&n);
                while(n>=count || n<0)
                {
                    printf("\nPossible stack indices:[0-%d]",count-1);
                    printf("\nEnter stack index: ");
                    scanf("%d",&n);
                }
                f=1;
                d=pop(s+n,&f);
                if(!f)
                {
                    printf("\nUnderflow!");
                }
                else
                    printf("\nElement popped: %d",d);
                break;
            case 4:
                printf("\nPossible stack indices:[0-%d]",count-1);
                printf("\nEnter stack index: ");
                scanf("%d",&n);
                while(n>=count || n<0)
                {
                    printf("\nPossible stack indices:[0-%d]",count-1);
                    printf("\nEnter stack index: ");
                    scanf("%d",&n);
                }
                f=1;
                d=peek(*(s+n),&f);
                if(!f)
                {
                    printf("\nUnderflow!");
                }
                else
                    printf("\nElement at stack top: %d",d);
                break;
            case 0:
                break;
            default:
                printf("\nInvalid input!");
        }
    }while(ch!=0);
    return 0;
}
