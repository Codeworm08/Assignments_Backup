#include <stdio.h>
#include <math.h>

void appCo()
{
    int w, op;
    float nop,reuse=0.90,effort,prod=25;
    int weight[3][3] = {{1, 2, 3}, {2, 5, 8}, {1, 1, 10}};
    int counts[3] = {14, 6, 10};
    char object[][15] = {"Screens", "Reports", "Components"};
    op = 0;
    for (int i = 0; i < 3; i++)
    {
        printf("\nSelect weight of %s in range of 0-2(inclusive)", object[i]);
        scanf("%d", &w);
        if (w < 0 || w > 2)
        {
            printf("\nInvalid Weight");
            return;
        }
        op += (counts[i] * weight[i][w]);
    }
    printf("\nObject point: %d", op);
    nop = (op*(100 - reuse))/100;
    printf("\nNew Object Point: %f",nop);
    effort = nop/prod;
    printf("\nEffort: %f person-month",effort);
}

void earlyDesign()
{
}

void postArch()
{
}

int main()
{
    int ch;
    printf("\n1->Application Composition Model\n2->Early Design Stage Model\n3->Post Architecture Stage Model\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        /* code */
        break;
    case 2:
        break;
    case 3:
        break;
    default:
        printf("\nInvalid Choice");
        break;
    }
    return 0;
}