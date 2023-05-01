#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int isPalindrome(char *s)
{
    char l, r;
    l = 0;
    r = strlen(s) - 1;
    while (l < r)
    {
        if (s[l] != s[r])
            return 0;
    }
    return 1;
}
int main()
{
    int fd[2];//P=>C
    int fq[2];//C=>P
    int x;
    char s[100], s1[100], buffer[100], ans[100];
    pid_t p;
    if (pipe(fd) == -1)
    {
        return 1;
    }
    if (pipe(fq) == -1)
    {
        return 1;
    }
    p = fork();
    if (p == -1)
    {
        return 2;
    }
    if (p > 0)//Parent
    {
        close(fd[0]);
        close(fq[1]);
        printf("\nEnter a string:");
        scanf("%s", s);
        if(!strcmp(s,"quit"))
            abort();
        write(fd[1], s, strlen(s));

        x = read(fq[0], s, sizeof(s));
        //printf("%d",strlen(s));
        close(fq[0]);
        close(fd[1]);
        printf("%s", s);
    }
    else
    {
        close(fq[0]);
        close(fd[1]);
        x = read(fd[0], s, strlen(s)*sizeof(s));
        //printf("\nValue received:%s",s);
        if (isPalindrome(s))
        {
            strcpy(s, "YES");
        }
        else
            strcpy(s, "NO");
            s[3]='\0';
        write(fq[1], s, strlen(s));
        //printf("In child: %s", s);
        close(fd[0]);
        close(fq[1]);
    }
    return 0;
}
