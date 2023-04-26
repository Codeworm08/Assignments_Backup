#include <stdio.h>
#include <stdlib.h>
struct list {
  int data;
  struct list *next;
};

typedef struct list * node;

node head=NULL;
node b=NULL;

node createNode(){
  node temp;
  temp = (node)malloc(sizeof(struct list));
  temp->next = NULL;
  return temp;
}

void createList(){
  int data,ch;
  node temp,p,t;
  if(head!=NULL)
  {
    printf("\nList already created!!");
    return;
  }
  do {
    printf("\nEnter value of new node: ");
    scanf("%d",&data);
    temp = createNode();
    temp->data = data;
    if(head == NULL){
      head = p= temp;
    }
    else {
      p->next=temp;
      p=temp;
    }
    printf("\n0->Stop\t1->Continue.. : ");
    scanf("%d",&ch);
  } while(ch);
  
}

void display()
{
  node t=head;
  if(head==NULL)
  {
    printf("\nEmpty List!!!");
    return;
  }
  printf("\n");
  while(t->next!=NULL) {
    printf("%d->",t->data);
    t=t->next;
  }
  printf("%d",t->data);
}

void insertFront(int data)
{
  node temp=(node)malloc(sizeof(struct list));
  temp->data=data;
  temp->next=head;
  head=temp;
}

void insertEnd(int data)
{
  node p,temp;
  temp=(node)malloc(sizeof(struct list));
  temp->data=data;
  p=head;
  while(p->next!=NULL){
    p=p->next;
  }
  p->next=temp;
  temp->next=NULL;
}

void insertK(int data,int key)
{
  int i;
  node p,temp; 
  p=head;
  for(i=1;i<key;i++){
    p=p->next;
    if(p==NULL){
      printf("\nEnd of List reached!!Can't Insert at %d",key);
      return;
    }
  }
  
    temp=(node)malloc(sizeof(struct list));
    temp->data=data;
    temp->next=p->next;
    p->next=temp;
  
}

void insertAfterValue(int data, int val)
{
  int i;
  node p,temp;
  p=head;
  while(p->data!=val)
  {
    p=p->next;
    if(p==NULL)
    {
      printf("\nValue does not exist in List!!");
      return;
    }
  }
  temp = (node)malloc(sizeof(struct list));
  temp->data=data;
  temp->next=p->next;
  p->next=temp;
}

void insertBeforeK(int data, int key)
{
  int i;
  node p,temp; 
  if(key==1){
    insertFront(data);
    return;
  }
  p=head;
  for(i=1;i<key-1;i++){
    p=p->next;
    if(p==NULL){
      printf("\nEnd of List reached!!Can't Insert at %d",key);
      return;
    }
  }
  
  temp=(node)malloc(sizeof(struct list));
  temp->data=data;
  temp->next=p->next;
  p->next=temp;

}

void insertBeforeValue(int data, int val)
{
  int i;
  node p,temp;
  p=head;
  if(p->data==val)
  {
    insertFront(data);
    return;
  }
  while(p->next->data!=val)
  {
    p=p->next;
    if(p->next==NULL)
    {
      printf("\nValue does not exist in List!!");
      return;
    }
  }
  temp = (node)malloc(sizeof(struct list));
  temp->data=data;
  temp->next=p->next;
  p->next=temp;
}

void delFirst()
{
  node p;
  if(head==NULL)
  {
    printf("\nEmpty List!!");
    return;
  }
  p=head;
  printf("\nElement deleted: %d",head->data);
  head=head->next;
  free(p);
}

void delEnd()
{
  node end,prev;
  
  if(head==NULL)
  {
    printf("\nEmpty List!!");
    return;
  }
  if(head->next==NULL)
  {
    delFirst();
    return;
  }
  end=head;
  prev=NULL;
  while(end->next)
  {
    prev=end;
    end=end->next;
  }
  prev->next=NULL;
  printf("\nElement deleted: %d",end->data); 
  free(end);
}

void delAftK(int k)
{
  node p,t;
  int i;
  if(head==NULL)
  {
    printf("\nEmpty List!!");
    return;
  }
  
  p=head;
  for(i=1;i<k;i++)
  {
    p=p->next;
    if(p==NULL)
    {
      printf("\nPosition does not exist in List!");
      return;
    }
  }
  if(p->next==NULL)
  {
    printf("\nReached End Of List!!");
    return;
  }
  t=p->next;
  p->next=t->next;
  t->next=NULL;
  free(t);

}
void delBefK(int k)
{
  node p,t;
  int i;
  k--;
  if(head==NULL)
  {
    printf("\nEmpty List!!");
    return;
  }
  if(k==1){
    delFirst();
    return;
  }
  else if(k<=0){
    printf("\nPosition statrs from 1!");
    return;
  }
  p=head;
  for(i=1;i<k-1;i++)
  {
    p=p->next;
    if(p==NULL)
    {
      printf("\nPosition does not exist in List!");
      return;
    }
  }
  t=p->next;
  p->next=t->next;
  t->next=NULL;
  free(t);
}
void delK(int k)
{
  node p,t;
  int i;
  if(head==NULL)
  {
    printf("\nEmpty List!!");
    return;
  }
  if(k==1){
    delFirst();
    return;
  }
  p=head;
  for(i=1;i<k-1;i++)
  {
    p=p->next;
    if(p==NULL)
    {
      printf("\nPosition does not exist in List!");
      return;
    }
  }
  t=p->next;
  p->next=t->next;
  t->next=NULL;
  free(t);
}

void delVal(int val)
{
  node prev,end;
  end=head;
  prev=NULL;
  if(head==NULL)
  {
    printf("\nList Empty!!");
    return;
  }
  while(end)
  {
    if(end->data==val)
      break;
    prev=end;
    end=end->next;
  }
  if(end==NULL)
  {
    printf("\n%d not present in List!",val);
    return;
  }
  if(prev==NULL){
    prev=head;
    head=head->next;
    prev->next=NULL;
    free(prev);
  }else{
     prev->next=end->next;
     end->next=NULL;
     free(end);
  }

 }

void revList()
{
  node cur,prev,next;
  if(head==NULL)
  {
    printf("\nEmpty List!!");
    return;
  }
  cur=head;
  prev=NULL;next=NULL;
  while(cur !=NULL)
  {
    next=cur->next;
    cur->next=prev;
    prev=cur;
    cur=next;
  }
  head=prev;
}

void sort()
{
  node l,h,temp;
  int t;
  if(head==NULL)
  {
    printf("\nEmpty List!!");
    return;
  }
  if(head->next==NULL)
  {
    return;
  }
  l=head;temp=NULL;
  while(l!=NULL)
  {
    h=l->next;
    while(h!=NULL)
    {
      if(h->data<l->data)
      {
        t=l->data;
        l->data=h->data;
        h->data=t;
      }
      h=h->next;
    } 
    l=l->next;
  }
}

void search(int p)
{
  node t;
  int i;
  if(head==NULL)
  {
    printf("\nList Empty!!");
    return;
  }
  t=head;
  i=1;
  while(t!=NULL)
  {
    if(t->data==p)
    {
      printf("\nValue found at node no: %d",i);
      return;
    }
    i++;
    t=t->next;
  }
  printf("\nValue not in List.");
}
void create2ndList()
{
  int data,ch;
  node temp,p,t;
  if(b!=NULL)
  {
    printf("\nList already created!!");
    return;
  }
  do {
    printf("\nEnter value of new node: ");
    scanf("%d",&data);
    temp = createNode();
    temp->data = data;
    if(b == NULL){
      b = p= temp;
    }
    else {
      p->next=temp;
      p=temp;
    }
    printf("\n0->Stop\t1->Continue.. : ");
    scanf("%d",&ch);
  } while(ch);

}

void merge()
{
  node p,t;
  if (head==NULL) 
  {
    printf("Original List is Empty!!");
    return;
  }
  printf("\nEnter the 2nd list:");
  create2ndList();
  p=head;
  while(p->next!=NULL)
    p=p->next;
  t=b;
  while (b!=NULL) 
  {
    p->next=b;
    b=b->next;
    p=p->next;
  }
  sort();
}

void concat()
{
  node p,t;
  if (head==NULL) 
  {
    printf("Original List is Empty!!");
    return;
  } 
  p=head;
  while(p->next!=NULL)
    p=p->next;
  t=b;
  while (b!=NULL) 
  {
    p->next=b;
    b=b->next;
    p=p->next;
  }
}

int equal()
{
  node p,t;
  if (head==NULL) 
  {
    printf("Original List is Empty!!");
    createList();
  } 
  p=head;
  t=b;
  while(p!=NULL && t!=NULL)
  {
    if(p->data!=t->data)
      return 0;
    p=p->next;
    t=t->next;
  }
  if(p!=NULL || t!=NULL)
    return 0;
  return 1;
}
int main()
{
  int ch,val,k;
  node t;
  do {
    printf("\n\n1->create List\n2->display\n3->insertFront\n4->insertEnd\n5->insertK");
    printf("\n6->InsertAfterValue\n7->insertBeforeK\n8->insertBeforeValue\n9->deleteFirst\n10->deleteEnd");
    printf("\n11->deleteAfterKthNode\n12->deleteBeforeKthNode\n13->deleteKthNode\n14->deleteNodeWithValue");
    printf("\n15->reverseList\n16->sortList\n17->searchList\n18->mergeList\n19->concatenateList\n20->checkEqual\n0->exit\n->");
    scanf("%d",&ch);
    switch (ch) {
      case 0:
        break;
      case 1:
        createList();
        break;
      case 2:
        printf("\nList:");
        display();  
        break;
      case 3:
        printf("\nEnter value to insert at front: ");
        scanf("%d",&val);
        insertFront(val);
        break;
      case 4:
        printf("\nEnter value to insert at end: ");
        scanf("%d",&val);
        insertEnd(val);
        break;
      case 5:
        printf("\nEnter position after which to insert: ");
        scanf("%d",&k);
        printf("\nEnter value to insert after %d: ",k);
        scanf("%d",&val);
        insertK(val,k);
        break;
      case 6:
        printf("\nEnter value after which to insert: ");
        scanf("%d",&k);
        printf("\nEnter value to be inserted: ");
        scanf("%d",&val);
        insertAfterValue(val,k);
        break;
      case 7:
        printf("\nEnter position before which to insert: ");
        scanf("%d",&k);
        printf("\nEnter value to insert: ");
        scanf("%d",&val);
        insertBeforeK(val,k);
        break;
      case 8:
        printf("\nEnter value before which to insert: ");
        scanf("%d",&k);
        printf("\nEnter value to be inserted: ");
        scanf("%d",&val);
        insertBeforeValue(val,k);
        break;
      case 9:
        delFirst();
        break;
      case 10:
        delEnd();
        break;
      case 11:
        printf("\nEnter position after which to delete: ");
        scanf("%d",&k);
        delAftK(k);
        break;
      case 12:
        printf("\nEnter position before which to delete: ");
        scanf("%d",&k);
        delBefK(k);
        break;
      case 13:
        printf("\nEnter position to be deleted: ");
        scanf("%d",&k);
        delK(k);
        break;
      case 14:
        printf("\nEnter value to be deleted!");
        scanf("%d",&val);
        delVal(val);
        break;
      case 15:
        printf("\nList Reversed!");
        revList();
        break;
      case 16:
        printf("\nList Sorted!!");
        sort();
        break;
      case 17:
        printf("\nEnter value to be found: ");
        scanf("%d",&val);
        search(val);
        break;
      case 18:
        merge();
        printf("\nLists Merged!");
        break;
      case 19:
        if(b==NULL)
        {
          printf("\nCreate 2nd List:\n");
          create2ndList();
        }
        concat();
        break;
      case 20:
        if(b==NULL)
        {
          printf("\nCreate 2nd List:\n");
          create2ndList();
        }
        if(equal())
          printf("The 2 lists are equal!");
        else
         printf("The 2 lists are not equal!");
        break;
      default:
        printf("\nInvalid choice!");
    }
  } while(ch);
  return 0;
}
