#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int fd[2]; // P=>C
    int fq[2]; // C=>P
    pid_t p;
    if (pipe(fd) == -1)
    {
        return 1;
    }
    if (pipe(fq) == -1)
    {
        return 1;
    }
    if (fork() != 0)
    {
        while (1)
        {
            char buffer[100] = {0}, s1[100];
            printf("\nEnter string(enter quit to exit): ");
            scanf("\n");
            scanf("%[^\n]", buffer);
            if ((strcmp("quit", buffer) == 0) || (strcmp("Quit", buffer) == 0))
            {
                exit(1);
            }
            strcpy(s1, buffer);
            write(fd[1], buffer, strlen(buffer));
            read(fq[0], buffer, 100);
            int l = strlen(buffer);
            buffer[l] = '\0';
            printf("%s", buffer);
        }
    }
    else
    {
        while (1)
        {
            char buffer[100] = {0}, s2[100];
            sleep(2);
            read(fd[0], buffer, 100);
            int l = strlen(buffer);
            buffer[l] = '\0';
            strcpy(s2, buffer);
            int i = 0, k = l - 1;
            while (i < k)
            {
                char t = buffer[i];
                buffer[i] = buffer[k];
                buffer[k] = t;
                i++;
                k--;
            }
            if (strcmp(s2, buffer) == 0)
                write(fq[1], "YES", 4);
            else
                write(fq[1], "NO", 3);
        }
    }
    return 0;
}
