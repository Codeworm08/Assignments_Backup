#include<stdio.h>
void displayDenom(int amount)
{
    int ten=0, twenty=0, fifty=0, hundred=0;
    hundred = amount/100;
    amount %= 100;
    fifty= amount/50;
    amount %= 50;
    twenty = amount/20;
    amount %= 20;
    ten = amount/10;
    amount %= 10;
    if(amount)
    {
        printf("NOT possible");
        return;
    }
        printf("\nRs.100: %d",hundred);
    
        printf("\nRs.50: %d",fifty);
    
        printf("\nRs.20: %d",twenty);
    
        printf("\nRs.10: %d\n",ten);
    
}
int main()
{
    int amount=0;
    printf("\nEnter ammount: ");
    scanf("%d",&amount);
    displayDenom(amount);
    return 0;
}