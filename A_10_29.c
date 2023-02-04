#include<stdio.h>
#include<string.h>
void truncate_zero(char s[100])
{
    int i,j;
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]!='0')
            break;
    }
    if(i>0)
    {
        for(j=0;s[i]!='\0';i++,j++)
            s[j]=s[i];
        s[j]='\0';
    }
    
}
void rev(char s[])
{
    int i,j;
    char t;
    for(i=0;s[i]!='\0';i++);
    i;
    for(j=0;j<i/2;j++)
    {
        t=s[j];
        s[j]=s[i-j-1];
        s[i-j-1]=t;
    }
    //s[i++]='\0';
}
int main()
{
    char s[100],og[100];
    int i,j;
    printf("\nEnter Number: ");
    scanf("%s",s);
    truncate_zero(s);
    strcpy(og,s);
    rev(s);
    truncate_zero(s);
    printf("\nReverse: %s",s);
    if(!strcmp(s,og))
        printf("\nIt is a palindrome.");
    else
        printf("\nIt is NOT a palindrome.");
    return 0;
}