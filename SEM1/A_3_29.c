#include <stdio.h>
#include <stdlib.h>
int findX(int n)
{
	int i=1,l,u;
  if(n==1)
    return 1;
    for(;i<n;i++)
    {
    	l=((i-1)*(i))/2;//Sum of lower half: 1->x-1
        u=((n-i)*(n+i+1))/2;//Sum of upper half: x+1->n
        if(l==u)
        	return i;
    }
    return -1;
}
int main() {
  int n,x;
  printf("\nEnter no of rooms: ");
  scanf("%d",&n);
  x=findX(n);
  if(x==-1)
  	printf("\nDoes not exist.");
  else
  	printf("\n%d\n",x);
  return 0;
}
