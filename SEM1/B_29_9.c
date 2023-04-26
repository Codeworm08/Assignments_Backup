#include<stdio.h>
#include<string.h>
void Strrev(char *s)
{
    int i,len;
    char t;
    for(i=0;s[i]!='\0';i++);
    len=i;
    if(len==1)
        return;
    for(i=0;i<len/2;i++)
    {
        t=s[i];
        s[i]=s[len-i-1];
        s[len-i-1]=t;
    }
}
void convert(int n, int base)
{
    char d[][100]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
    char s[200];
    int i=0,t=n;
    strcpy(s,"");
    if(base==1)
    {
        for(i=0;i<n;i++)
            strcat(s,"1");
    }
    else
    {
        while (t>0)
        {

            strcat(s,d[t%base]);
            t/=base;
        }
    }
    
    if(n==0)
        strcpy(s,"0");
    Strrev(s);
    printf("Base%d: %s",base,s);
    
}
int main()
{
    int n,base;
    printf("\nEnter decimal number: ");
    scanf("%d",&n);
    printf("\nEnter base to be converted to: ");
    scanf("%d",&base);
    convert(n,base);
    return 0;
}