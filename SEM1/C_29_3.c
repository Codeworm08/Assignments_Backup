#include <stdio.h>
#include <stdlib.h>
struct account
{
    int accountNumber;
    char *Name;
    float Balance;
};
typedef struct account acc;
void printBelow1000(acc *a, int n)
{
    int i, j;
    printf("\nAcounts with balance below Rs.1000:\n");
    for (i = 0; i < n; i++)
    {
        if (a[i].Balance < 1000)
        {
            printf("\nAccount Number: %d", a[i].accountNumber);
            printf("\n\tName: %s", a[i].Name);
            printf("\tBalance: %.2f", a[i].Balance);
        }
    }
}
void input(acc *a)
{
    printf("\nEnter account number: ");
    scanf("%d", &a->accountNumber);
    getchar();
    a->Name = (char *)malloc(sizeof(char) * 200);
    printf("\nEnter name: ");
    fgets(a->Name, 200, stdin);
    printf("\nEnter Balance:");
    scanf("%f", &a->Balance);
}
void print(acc *a)
{
    printf("\nAccount Number: %d, Name: %s, Balance: %.2f", a->accountNumber, a->Name, a->Balance);
}
void deposit(acc *a, float amount)
{
    a->Balance += amount;
    print(a);
}
void withdraw(acc *a, float amount)
{
    if (a->Balance < amount)
    {
        printf("\nBalance is insufficient for specific withdrawal.");
        return;
    }
    a->Balance -= amount;
    print(a);
}
int main()
{
    int n, i, code, an;
    char s[200];
    float amount;
    acc *as;
    printf("\nEnter no of accounts: ");
    scanf("%d", &n);
    as = (acc *)malloc(sizeof(acc) * n);
    for (i = 0; i < n; i++)
    {
        input(&as[i]);
    }
    printBelow1000(as, n);
    do
    {
        printf("\nAccount number to manipulate: ");
        scanf("%d", &an);
        for (i = 0; i < n; i++)
        {
            if (as[i].accountNumber == an)
                break;
        }
        if (i >= n)
        {
            printf("\nAccount does not exist!");
            continue;
        }
        printf("\nEnter\n\t1 to deposit.\n\t0 to withdraw\n\t2 to quit: ");
        scanf("%d", &code);
        getchar();

        switch (code)
        {
        case 1:
            printf("\nEnter amount: ");
            scanf("%f", &amount);
            deposit(&as[i], amount);
            break;
        case 0:
            printf("\nEnter amount: ");
            scanf("%f", &amount);
            withdraw(&as[i], amount);
            break;
        }
    } while (code != 2);

    return 0;
}