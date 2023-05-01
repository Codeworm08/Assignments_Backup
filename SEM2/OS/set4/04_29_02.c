#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_RANGE 100
int is_prime(int n)
{
    if (n <= 1)
        return 0;
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int l, r, i, children;
    pid_t pid;
    l = 1;
    r = 100000;
    children = 0;
    for (i = 0; i < 10; i++)
    {

        pid = fork();
        children++;
        if (pid < 0)
        {
            printf("Unable to create child process.\n");
        }
        else if (pid == 0)
        {
            break;
        }
        else
        {
            l += 100000;
            r += 100000;

            if (i == 9)
                while (wait(NULL) > 0);
        }
    }
    if (children > 0)
    {
        for (int j = l; j <= r; j++)
        {
            if (is_prime(j))
                printf("%d\t", j);
        }
        printf("\nChild process %d finished.\n", children);
        exit(0);
    }
    return 0;
}