#include <stdio.h>
#include <stdlib.h>
int ex2d(int n, int k)
{
    int people[n][2];
    for (int i = 0; i < n; i++)
    {
        people[i][0] = i;
        people[i][1] = 0;
    }
    int current = 0;
    while (1)
    {
        int count = people[current][1]; // number of people to skip
        for (int i = 0; i < n; i++)
        {
            if (people[i][1] == 0)
            {
                count--;
                if (count == 0)
                {
                    // execute the next person
                    people[i][1] = 1;
                    current = (i + 1) % n;
                    break;
                }
            }
        }
        int left = 0;
        for (int i = 0; i < n; i++)
        {
            if (people[i][1] == 0)
                left++;
        }
        if (left == 1)
            break;
        people[current][1] = k;
    }
    for (int i = 0; i < n; i++)
    {
        if (people[i][1] == 0)
        {
            return i;
        }
    }
    return 0;
}
int exL
int main()
{
    int n, k;
    printf("\nEnter no of people: ");
    scanf("%d", &n);
    printf("\nEnter skips: ");
    scanf("%d", &k);
    printf("\n%d", ex2d(n, k));
    return 0;
}