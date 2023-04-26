#include<stdio.h>
int Strlen(char *s)
{
    int i;
    for(i=0;s[i]!='\0';i++);
    return --i;
}
void Strcpy(char *s1, char *s2)
{
    int i;
    for(i=0;s2[i]!='\0';i++)
        *(s1+i)=*(s2+i);
    *(s1+i)='\0';
}
void Strcat(char *s1, char *s2)
{
    int i,j;
    for(i=0;s1[i]!='\0';i++);
    for(j=0;s2[j]!='\0';j++)
        s1[i++]=s2[j];
    s1[i]='\0';
}
void Strrev(char *s)
{
    int i,len;
    char t;
    for(i=0;s[i]!='\0';i++);
    len=i;
    for(i=0;i<len/2;i++)
    {
        t=s[i];
        s[i]=s[len-i-1];
        s[len-i-1]=t;
    }
}
int Strcmp(char *s1, char *s2)
{
    int diff,i;
    for(i=0;s1[i]!=0 && s2[i]!='\0';i++)
    {
        diff=(int)s1[i]-(int)s2[i];
        if(diff)
            return diff;
    }
    if(s1[i]!='\0')
        return (int)s1[i];
    if(s2[i]!='\0')
        return -1 * (int)s2[i];
    return 0;
}
int main()
{
    int choice=7,cmp,len;
    char s1[100],s2[100];
    do
    {
        printf("\n1.Strlen()\n2.Strcpy()\n3.Strcat()\n4.Strrev()\n5.Strcmp()\n-1 to Quit.");
        scanf("%d",&choice);
        fflush(stdin);
        switch (choice)
        {
        case 1:
            printf("\nEnter String:");
            fflush(stdin);
            scanf(" %[^\n]s",s1);
            len=Strlen(s1);
            printf("\nLength: %d",len);
            break;
        case 2:
            printf("\nEnter 1st String: ");
            fflush(stdin);
            scanf(" %[^\n]s",s1);
            printf("\nEnter 2nd String: ");
            scanf(" %[^\n]s",s2);
            Strcpy(s1,s2);
            printf("\nCopied String: %s",s1);
            break;
        case 3:
            printf("\nEnter 1st String: ");
            fflush(stdin);
            scanf(" %[^\n]s",s1);
            printf("\nEnter 2nd String: ");
            fflush(stdin);
            scanf(" %[^\n]s",s2);
            Strcat(s1,s2);
            printf("\nConcatted String: %s",s1);
            break;
        case 4:
            printf("\nEnter String: ");
            fflush(stdin);
            scanf(" %[^\n]s",s1);
            Strrev(s1);
            printf("\nReverse: %s",s1);
            break;
        case 5:
            printf("\nEnter 1st String: ");
            fflush(stdin);
            scanf(" %[^\n]s",s1);
            fflush(stdin);
            printf("\nEnter 2nd String: ");
            scanf(" %[^\n]s",s2);
            Strcmp(s1,s2);
            cmp = Strcmp(s1,s2);
            printf("\nComparison: %d",cmp);
            break;
        case -1:
            break;
        default:
            printf("\nInvalid choice!");
        }
    } while (choice!=-1);
    
    return 0;
}