#include <stdio.h>
#include <stdlib.h>
struct Node{
  int coeff;
  int pow;
  struct Node* next;
};
typedef struct Node* node;
void createNode(int c, int p, node*temp)
{
  node r,t;
  r=(node)malloc(sizeof(struct Node));
  r->next=NULL;
  r->coeff=c;
  r->pow=p;
  
  if (*temp==NULL){
    *temp=r;
  }
  else {
      t=*temp;
    while (t->next!=NULL)
      t=t->next;
    t->next=r;
  }
}

void sort(node* head)
{
  node l,h;
  int p,c;
  if(*head==NULL)
  {
    printf("\nEmpty List!!");
    return;
  }
  l=*head;
  if(l->next==NULL)
  {
    return;
  } 
  while(l!=NULL)
  {
    h=l->next;
    while(h!=NULL)
    {
      if(h->pow<l->pow)
      {
        p=l->pow;
        c=l->coeff;
        l->pow=h->pow;
        h->pow=p;
        l->coeff=h->coeff;
        h->coeff=c;
      }
      h=h->next;
    } 
    l=l->next;
  }
}
void show(node p)
{
  node t;
  t=p;
  if(t==NULL)
    return;
  while (t!=NULL) {
    printf(" %dx^%d", t->coeff, t->pow);
    if (t->next != NULL){
      if (t->next->coeff >=0)
        printf(" +");
    }
    t=t->next;
  }
}

int main()
{
  node p1,p2;
  p1=NULL;p2=NULL;
  createNode(3, 2, &p1);
  createNode(-1, 1, &p1);
  createNode(4, 3, &p1);
  sort(&p1);
  show(p1);
  return 0;
}
