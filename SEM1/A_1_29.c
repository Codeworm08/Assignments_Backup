#include<stdio.h>
int main()
{
    int choice;float c,f;
    printf("\nEnter 1 for Celsius to Fahrenheit.\nEnter 2 for Fahrenheit to Celsius.\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("\nEnter celsius temperature: ");
            scanf("%f",&c);
            f=(9*c/5)+32;
            printf("\nTemperature in Fahrenheit is: %f",f);
            break;
        case 2:
            printf("\nEnter fahrenheit temperature: ");
            scanf("%f",&f);
            c =((f-32)*5)/9;
            printf("\nTemperature in Celsius is: %f",c);
            break;
        default:
            printf("\nInvalid choice!");
    }
}