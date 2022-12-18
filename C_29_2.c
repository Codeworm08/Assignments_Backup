#include <stdio.h>
struct time
{
    int hh, mm, ss;
};
typedef struct time time;
void input(time *t)
{
    int hh, mm, ss;
    printf("\nEnter hour: ");
    scanf("%d", &hh);
    printf("\nEnter min: ");
    scanf("%d", &mm);
    printf("\nEnter seconds: ");
    scanf("%d", &ss);
    if (mm >= 60)
    {
        printf("\nInvalid minutes!.");
        return;
    }
    if (ss >= 60)
    {
        printf("\nInvalid seconds!.");
        return;
    }
    t->hh = hh;
    t->mm = mm;
    t->ss = ss;
}
time add(time *t1, time *t2)
{
    time sum;
    int s, m;
    s = t1->ss + t2->ss;
    m = t1->mm + t2->mm + s / 60;
    sum.ss = s % 60;
    sum.mm = m % 60;
    sum.hh = t1->hh + t2->hh + m / 60;
    return sum;
}
void print(time *t)
{
    printf("\n %d:%d:%d", t->hh, t->mm, t->ss);
}
int main()
{
    time t1, t2, t3;
    input(&t1);
    input(&t2);
    t3 = add(&t1, &t2);
    printf("\nTime1:");
    print(&t1);
    printf("\nTime2:");
    print(&t2);
    printf("\nTime1 + Time2:");
    print(&t3);
    return 0;
}