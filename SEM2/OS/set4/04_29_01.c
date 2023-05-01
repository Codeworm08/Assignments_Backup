#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();
    int cstatus;
    if (pid == 0)
    {
        printf("Child => PPID: %d PID: %d\n", getppid(), getpid());
        exit(EXIT_SUCCESS);
    }
    else if (pid > 0)
    {
        printf("\nParent => PID: %d\n", getpid());
        printf("\nWaiting for child process to finish.\n");
        wait(&cstatus);
        printf("\nChild process finished.\n");
        printf("\nChild exited with status: %d", cstatus);
    }
    else
    {
        printf("Unable to create child process.\n");
    }
    return EXIT_SUCCESS;
}