#include<stdio.h>

void recrev(char *s)
{
    if(*s)
    {
        recrev(s+1);
        printf("%c",*s);
    }
}
void itrrev(char *s)
{
    int i;
    for(i=0;s[i]!='\0';i++);
    i--;
    for(;i>=0;i--)
        printf("%c",s[i]);
}
int main()
{
    char s[300];
    printf("Enter a string to bre reversed: ");
    fgets(s,299,stdin);
    printf("\nReverse iterative:");
    itrrev(s);
    printf("\nReverse recursive:");
    recrev(s);
    return 0; 
}
