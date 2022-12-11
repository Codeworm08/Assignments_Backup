#include<stdio.h>
#include<stdlib.h>
struct date
{
    int dd;
    int mm;
    int yyyy;
};
typedef struct date date;
date* create_date(date *d)
{
    d = (date *)malloc(sizeof(date));
    d->dd=0;
    d->mm=0;
    d->yyyy=0;
    return d;
}
date*set_date(date *d,int dd,int mm,int yyyy)
{
    if(yyyy<0)
    {
        printf("\nInvalid year!");
        return NULL;
    }
    if(mm<=0 || mm>12)
    {
        printf("\nInvalid month");
        return NULL;
    }
    if(dd<=0)
    {
        printf("\nInvalid day.");
        return NULL;
    }
    if(mm==2 && dd>29)
    {
        printf("\nDay %d not present in February.",dd);
        return NULL;
    }
    if((mm==4 || mm==6 || mm==9 || mm==11)&& dd>30)
    {
        printf("\nMonth %d has only 30 days!",mm);
        return NULL;
    }
    if(dd>31)
    {
        printf("\nNo month has %d days",dd);
        return NULL;
    }
    d->dd=dd;
    d->mm=mm;
    d->yyyy=yyyy;
}
void check_equality(date *d1, date *d2)
{
    if(d1->yyyy == d2->yyyy && d1->mm == d2->mm && d1->dd == d2->dd)
        printf("\nEqual");
    else
        printf("\nUnequal");
}
int main()
{
    int dd,mm,yyyy;
    date *d1=NULL,*d2=NULL;
    d1=create_date(d1);
    d2=create_date(d2);
    printf("\nEnter 1st date:");
    printf("\nDay: ");
    scanf("%d",&dd);
    printf("\nMonth: ");
    scanf("%d",&mm);
    printf("\nYear: ");
    scanf("%d",&yyyy);
    d1=set_date(d1,dd,mm,yyyy);
    printf("\nEnter 2nd date:");
    printf("\nDay: ");
    scanf("%d",&dd);
    printf("\nMonth: ");
    scanf("%d",&mm);
    printf("\nYear: ");
    scanf("%d",&yyyy);
    d2=set_date(d2,dd,mm,yyyy);
    check_equality(d1,d2);
    return 0;
}