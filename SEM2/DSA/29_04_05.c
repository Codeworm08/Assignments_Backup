#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

//Create node
node* create(int n)
{
	node *t=(node *)malloc(sizeof(node));
	t->data=n;
	t->left=NULL;
	t->right=NULL;
	return(t);
}
void createAVL(node**p)
{
    *p = NULL;
    printf("Empty AVL Tree is created\n");
    return;
}
//height
int height(node *p)
{
	int lh,rh;
	if(p==NULL)
		return 0;
	lh=height(p->left);
	rh=height(p->right);
	if(lh>rh)
		return(lh+1);
	else
		return(rh+1);	
}

//get balance factor
int getbalancefactor(node *p)
{
	if(p==NULL)
		return(-1);
	return(height(p->left)-height(p->right));
}

//Rotate left
node* rotateleft(node *p)
{
	node *q=p->right,*t=q->left;
	q->left=p;
	p->right=t;
	return(q);
}

//Rotate right
node* rotateright(node *p)
{
	node *q=p->left,*t=q->right;
	q->right=p;
	p->left=t;
	return(q);
}

node* insert(node *p,int n)
{
	int b;	
	if(p==NULL)
		return(create(n));
	if(p->data==n)
	{
		printf("No dublicate data please\n");
		return(p);
	}
	else if(p->data<n)
		p->right=insert(p->right,n);
	else
		p->left=insert(p->left,n);
	b=getbalancefactor(p);
	//left left
	if((b>1)&&((p->left->data)>n))
		{
			printf("Right Rotation\n");
			return(rotateright(p));
		}
	//right right
	if((b<-1)&&((p->right->data)<n))
		{
			printf("Left rotation\n");
			return(rotateleft(p));
		}
	//left right
	if((b>1)&&(p->left->data<n))
	{
		printf("Left rotation\n");
		p->left=rotateleft(p->left);
		printf("Right Rotation\n");
		return(rotateright(p));
	}
	//right left
	if((b<-1)&&(p->right->data>n))
	{
		printf("Right Rotation\n");
		p->right=rotateright(p->right);
		printf("Left rotation\n");
		return(rotateleft(p));
	}
	return(p);
}

//pre order traversal
void preorder(node *p)
{
	if(p==NULL)
		return;
	printf("%d ",p->data);
	preorder(p->left);
	preorder(p->right);
	return;
}

//In order traversal
void inorder(node *p)
{
	if(p==NULL)
		return;
	inorder(p->left);
	printf("%d ",p->data);
	inorder(p->right);
	return;
}

//Post order traversal
void postorder(node *p)
{
	if(p==NULL)
		return;
	postorder(p->left);
	postorder(p->right);
	printf("%d ",p->data);
	return;
}

//Search iterative
node* search(node *p,int n)
{
	node *t=p;
	if(p==NULL)
		return(NULL);
	while(t!=NULL)
	{
		if(t->data==n)
			return(t);
		if(t->data<n)
			t=t->right;
		else
			t=t->left;
	}
	return(NULL);
}

//Smallest element
node* small(node *p)
{
	node *c=p;
	while(c->left!=NULL)
		c=c->left;
	return(c);
}

//delete
node* deletenode(node *p,int n)
{
	node *t;
	int b;
	if(p==NULL)
		return(p);
	if(p->data<n)
		p->right=deletenode(p->right,n);
	else if(p->data>n)
		p->left=deletenode(p->left,n);
	else
	{
		if(p->left==NULL)
		{
			t=p->right;
			free(p);
			return(t);	
		}
		if(p->right==NULL)
		{
			t=p->left;
			free(p);
			return(t);
		}
		t=small(p->right);
		p->data=t->data;
		p->right=deletenode(p->right,t->data);	
	}
	b=getbalancefactor(p);
	//left left
	if(b==2&&getbalancefactor(p->left)>=0)
	{
		printf("Right Rotation\n");
		return(rotateright(p));
	}
	//right right
	if(b==-2&&getbalancefactor(p->right)<=0)
	{
		printf("Left Rotation\n");
		return(rotateleft(p));
	}
	//left right
	if (b==2&&getbalancefactor(p->left)==-1)
	{
		printf("Left Rotation\n");
		p->left=rotateleft(p->left);
		printf("Right Rotation\n");
		return(rotateright(p));
	}
	//right left
	if (b==-2&&getbalancefactor(p->right)==1)
	{
		printf("Right Rotation\n");
		p->right=rotateright(p->right);
		printf("Left Rotation\n");
		return(rotateleft(p));
	}
	return(p);
}

int main()
{
	node *root=NULL;
	int choice,n;
	do
	{
		printf("\nEnter option :\n");
		printf("0 -> Exit\n1 ->Create\n2->Insert\n3->Search\n4->Delete");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				break;
            case 1:
                createAVL(&root);
                break;
			case 2:
				printf("Enter the data to be inserted = ");
				scanf("%d",&n);
				root=insert(root,n);
				break;
			case 3:
				printf("Enter the data to be search = ");
				scanf("%d",&n);
				if(search(root,n))
					printf("Value found\n");
				else
					printf("Value not found");
				break;
			case 4:
				printf("Enter the data to be deleted = ");
				scanf("%d",&n);
				root=deletenode(root,n);
				break;
			default:
				printf("Enter a number between 0 to 7\n");
				break;
		}
	}while(choice!=0);
	return(0);
}
