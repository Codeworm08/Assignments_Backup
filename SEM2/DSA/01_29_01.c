#include<stdio.h>
#include<stdlib.h>

int create(int **a)
{
    int i,ch;

    *a=(int*)malloc(sizeof(int));
    i=0;
    while(1)
    {
        printf("\nEnter a number:");
        scanf("%d",&a[0][i]);
        printf("\n1 to continue.0->Stop : ");
        scanf("%d",&ch);
        if(ch)
        {
            i+=1;
            *a=realloc(*a,sizeof(int)*(i+1));
        }
        else break;
    }
    return i+1;
}
void display(int *a,int n)
{
    int i;
    if(a==NULL)
    {
    	printf("\nArray Empty!!");
    	return;
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
int count(int *a,int n)
{
	if(a==NULL)
    {
    	printf("\nArray Empty!!");
    	return -1;
    }
    return n;
}
void reverse(int *a,int n)
{
    int l,r,t;
    if(a==NULL)
    {
    	printf("\nArray Empty!!");
    	return;
    }
    l=0;
    r=n-1;
    while(l<r)
    {
        t=a[l];
        a[l]=a[r];
        a[r]=t;
        l+=1;
        r-=1;
    }
}
void aindex(int *a, int n,int p)
{
   int i,j=0,f=0;
   if(a==NULL)
    {
    	printf("\nArray Empty!!");
    	return;
    }
   for(i=0;i<n;i++)
   {
   		if (a[i]==p)
   		{
   			f=1;
   			printf("\n%d found at %d(0 based indexing)",p,i);
   		}
   }
   if(!f)
   	printf("\nElement not found in the array!");
}
void indexed(int *a,int n,int ind)
{
	int i=0;
	if(a==NULL)
    {
    	printf("\nArray Empty!!");
    	return;
    }
	if(ind<0 || ind>=n)
	{
		printf("\nInvalid index. Index should be between:[0-%d]",n-1);
		return;
	}
	printf("\nIndexed element at %d => %d",ind,a[ind]);
}
void insert(int **a, int *n,int p,int in)
{
	int i;
	if(*a==NULL)
    {
    	printf("\nArray Empty!!");
    	return;
    }
	if(in<0 || in>=*n)
	{
		printf("\nInvalid index. Index should be between:[0-%d]",*n-1);
		return;
	}
	*a=realloc(*a,sizeof(int)*(*n+1));
	*n=*n+1;
	for(i=*n-1;i>in;i--)
		a[0][i]=a[0][i-1];
	a[0][in]=p;
}
void delete(int **a, int *n,int in)
{
	int i;
	if(*a==NULL)
    {
    	printf("\nArray Empty!!");
    	return;
    }
	if(in<0 || in>=*n)
	{
		printf("\nInvalid index. Index should be between:[0-%d]",*n-1);
		return;
	}
	for(i=in;i<*n-1;i++)
	{
		a[0][i]=a[0][i+1];
	}
	*n=*n-1;
	*a=realloc(*a,sizeof(int)*(*n));
}

void merge(int **a,int *n)
{
	int i,j,*b=NULL,n2,s;
	if(*a==NULL)
    {
    	printf("\nArray Empty!!");
    	return;
    }
	printf("\nCreate 2nd array:");
	n2=create(&b);
	s=*n+n2;
	*a=realloc(*a,sizeof(int)*(s));
	for(i=0;i<n2;i++)
		a[0][*n+i]=b[i];
	*n=s;
}
void split(int *a, int n)
{
	int *s1,*s2,i,k;
	if(a==NULL)
    {
    	printf("\nArray Empty!!");
    	return;
    }
	s1=(int*)malloc(sizeof(int)*(n/2));
	s2=(int*)malloc(sizeof(int)*(n/2));
	for(i=0;i<n/2;i++)
		s1[i]=a[i];
	k=0;
	for(;i<n;i++)
		s2[k++]=a[i];
	printf("\n1st half:");
	display(s1,n/2);
	printf("\n2nd half:");
	display(s2,k);
}
void sort(int *a, int n)
{
	int i,j,t;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}		
		}
	}
}
void search(int *a, int n, int p)
{
	int i=0,f=0;
	for(;i<n;i++)
	{
		if(a[i]==p)
		{
			f=1;
			printf("\nElement found at index: %d",i);
			break;
		}
	}
	if(!f)
		printf("\nElement not found!");
}
int main()
{
    int *a=NULL,*b=NULL,i,n,ch,cont,in,p;
    do{
    	    printf("\n1->create\n2->display\n3->count\n4->reverse\n5->find index\n6->indexed element\n7->insert\n8->delete\n9->merge\n10>split\n11->sort\n12->search");
    	    scanf("%d",&ch);
    	    switch(ch)
    	    {
    	    	case 1:
    	    			printf("\nCreate array:");
    	    			n=create(&a);
    	    			break;
    	    	case 2:
    	    			display(a,n);
    	    			break;
    	    	case 3:
    	    			printf("%d",count(a,n));
    	    			break;
    	    	case 4:
    	    			printf("\nReversed");
    	    			reverse(a,n);
    	    			display(a,n);
    	    			break;
    	    	case 5:
    	    			printf("\nEnter element to be found: ");
    	    			scanf("%d",&p);
    	    			aindex(a,n,p);
    	    			break;
    	    	case 6:
    	    			printf("\nEnter index: ");
    	    			scanf("%d",&p);
    	    			indexed(a,n,p);
    	    			break;
    	    	case 7:
    	    			printf("\nEnter element to be inserted: ");
    	    			scanf("%d",&p);
    	    			printf("\nEnter index to be inserted at: ");
    	    			scanf("%d",&in);
    	    			insert(&a,&n,p,in);
    	    			break;
    	    	case 8:
    	    			printf("\nEnter index to be deleted: ");
    	    			scanf("%d",&in);
    	    			delete(&a,&n,in);
    	    			break;
    	    	case 9:
    	    			merge(&a,&n);
    	    			break;
    	    	case 10:
    	    			split(a,n);
    	    			break;
    	    	case 11:
    	    			sort(a,n);
    	    			printf("\nSorted: ");
    	    			display(a,n);
    	    			break;
    	    	case 12:
    	    			printf("\nEnter element to be found: ");
    	    			scanf("%d",&p);
    	    			search(a,n,p);
    	    			break;
    	    	default:
    	    			printf("\nInvalid choice!!");
    	    			
    	    }
    	    printf("\n\n0->stop\n1->continue");
    	    scanf("%d",&cont);
    }while(cont);

    return 0;
}
