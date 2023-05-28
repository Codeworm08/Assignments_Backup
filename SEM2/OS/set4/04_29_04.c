#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{
    int status,ch;
    do
    {
        printf("\n1.ls\n2.pwd\n3uname\n4.exit\n->");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            if(fork()==0)
            {
                printf("\nls:\n");
                char *str1[]={"/bin/ls","-l",NULL};
                execv("/bin/ls",str1);
            }
            else
            {
                wait(&status);
            }
            break;
        case 2:
            if(fork()==0)
            {
                printf("\npwd:\n");
                char *str2[]={"/bin/pwd",NULL};
                execv("/bin/pwd",str2);
            }
            else
            {
                wait(&status);
            }
            break;
        case 3:
            if(fork()==0)
            {
                printf("\nuname:\n");
                char *str3[]={"/bin/uname",NULL};
                execv("/bin/uname",str3);
            }
            else
            {
                wait(&status);
            }
            break;
        case 4:
            printf("\nBye\n");
            break;
        default:
            printf("\nInvalid input\n");

        }
    } while (ch!=4);
    
    return 0;
}