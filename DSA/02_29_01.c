#include <stdio.h>
#include <stdlib.h>
struct node {
  int data;
  struct node *next;
};
typedef struct node * node;

node createNode(){
  node temp;
  temp = (node)malloc(sizeof(struct node));
  temp->next = NULL;
  return temp;
}

node createList(node head){
  int data,ch;
  node temp,p;
  do {
    printf("\nEnter value of new node: ");
    scanf("%d",&data);
    temp = createNode();
    temp->data = data;
    if(head == NULL){
      head = temp;
    }
    else {
      p=head;
      while(p->next != NULL){
        p=p->next;
      }
      p->next=temp;
    }
    printf("\n0->Stop\t1->Continue.. : ");
    scanf("%d",&ch);
  } while(ch);
  return head;
}

int main()
{
  int ch;
  node head;
  do {
    printf("\n1->create List\n0->exit");
    scanf("%d",&ch);
    switch (ch) {
      case 0:
        break;
      case 1:
        head=createList(head);
        break;
    }
  } while(ch);
  return 0;
}
