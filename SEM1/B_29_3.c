#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void counts(char *s,int *a, int *b)
{
    char w[300];
    int i,j;
    strcpy(w,"");

    if(s[0]>=65 && s[0]<=90)
        (*b)++;
    
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]!=' ')
            strncat(w,&s[i],1);
        else
        {
            if(strcmp(w,"an")==0||strcmp(w,"An")==0||strcmp(w,"a")==0||strcmp(w,"A")==0||strcmp(w,"the")==0||strcmp(w,"The")==0)
                (*a)++;
            strcpy(w,"");
            if((int)s[i+1]>=65 && (int)s[i+1]<=90)
                (*b)++;
        }
    }
    //strncat(w,&s[i-1],1);
    //printf("%c",w[0]);
    if(strcmp(w,"an")==0||strcmp(w,"An")==0||strcmp(w,"a")==0||strcmp(w,"A")==0||strcmp(w,"the")==0||strcmp(w,"The")==0)
        (*a)++;
    if((int)w[0]>=65 && (int)w[0]<=90)
        (*b)++;
}
int main()
{
    char str[300];
    int articles=0,capitals=0,i=0;
    printf("\nEnter sentence:\n");
    scanf("%[^#]s",str);
    for(i=0;str[i]!='\0';i++);
    /*if(i<80)
    {
        printf("\nNeed more than 80 characters!");
        exit(1);
    }*/
    counts(str,&articles,&capitals);
    printf("\nNo of articles: %d",articles);
    printf("\nNo of capitalized words: %d", capitals);
    return 0;
}