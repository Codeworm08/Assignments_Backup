#include<stdio.h>
#include<stdlib.h>
int substr(char *s1, char *s2)
{
    int l1,l2,i,j,f=-1;
    for(l1=0;s1[l1]!='\0';l1++);
    for(l2=0;s2[l2]!='\0';l2++);
    for(i=0;i<=l1-l2;i++)
    {
        if(s1[i]==s2[0])
        {
            for(j=1;j<l2;j++)
            {
                f=1;
                if(s2[j]!=s1[i+j])
                {
                    f=0;
                    break;
                }
            }
            if(f==1)
                return i;
            f=-1;
        }
    }
    return 0;
}
int main()
{
    char *s1,*s2;
    int n1,n2,ind;
    printf("\nEnter size of Main String: ");
    scanf("%d",&n1);
    printf("\nEnter size of Sub String: ");
    scanf("%d",&n2);
    s1 = (char *)malloc(sizeof(char)*n1);
    s2 = (char *)malloc(sizeof(char)*n2);
    getchar();
    printf("\nMain String:");
    
    fgets(s1,n1,stdin);
    getchar();
    printf("\nSub String:");
    
    fgets(s2,n2,stdin);
    getchar();
    ind=substr(s1,s2);
    if(ind)
        printf("\nString found at: %d",ind);
    else
        printf("\nString not found.");
    return 0;
}