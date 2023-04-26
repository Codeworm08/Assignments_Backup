#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void sort(char **c, int n)
{
    int i,j;
    char *temp;
    temp=(char*)malloc(sizeof(char)*200);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(strcmp(c[j],c[j+1])>0)
            {
                strcpy(temp,c[j]);
                strcpy(c[j],c[j+1]);
                strcpy(c[j+1],temp);
            }
        }
    }
}
int main()
{
    int n,i;
    char **c;
    printf("\nEnter no of countries: ");
    scanf("%d",&n);
    c =(char **)malloc(sizeof(char*)*n);
    getchar();
    for(i=0;i<n;i++)
    {
        *(c+i)=(char *)malloc(sizeof(char)*200);
        printf("\nEnter country %d: ",i+1);
        scanf("%[^\n]s",c[i]);
        getchar();
    }
    sort(c,n);
    printf("\nSorted Country Names:\n");
    for(i=0;i<n;i++)
        printf("\n%s",c[i]);
    free(c);
    return 0;
}
