#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "sema.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
void sem_wait(int*sem)
{
    while(__atomic_load_n(sem,__ATOMIC_SEQ_CST)<=0);
    __atomic_fetch_sub(sem,1,__ATOMIC_SEQ_CST);
}
void sem_signal(int*sem)
{
    __atomic_fetch_add(sem,1,__ATOMIC_SEQ_CST);
}
int main()
{
    int semC;
    int *semaphores,*shared_var;
    key_t key1 = 1011;
    key_t key2 = 1012;
    size_t seg_size = sizeof(int)*3;
    int shm_id,shm_id1;
    int status;
    pid_t p_arr[3],pid;
    shm_id = shmget(key1, seg_size, IPC_CREAT | 0666);
    shm_id1 = shmget(key2, seg_size, IPC_CREAT|0666);
    semaphores = (int*)shmat(shm_id,NULL,0);
    shared_var = (int*)shmat(shm_id1,NULL,0);
    semaphores[0]=1;
    semaphores[1]=0;
    semaphores[2]=0;
    shared_var[0]=0;
    shared_var[1]=10;
    for(int i=0;i<3;i++){
        p_arr[i]=pid=fork();
        if(pid==0)
        {
            if(i==0)
            {
                while(1)
                {
                    sem_wait(&semaphores[0]);
                    if(shared_var[1]<=0)
                    {
                        sem_signal(&semaphores[1]);
                        sem_signal(&semaphores[2]);
                        break;
                        
                    }
                    printf("A");
                   
                    fflush(stdout);
                    sem_signal(&semaphores[1]);
                }
                shmdt(semaphores);
                shmdt(shared_var);
                exit(0);
            }
            else if(i==1)
            {
                while (1)
                {
                    sem_wait(&semaphores[1]);
                    if(shared_var[1] <=0)
                        break;
                    printf("B");
                    fflush(stdout);
                    if(shared_var[0]==0)
                        sem_signal(&semaphores[2]);
                    else
                    {
                        shared_var[1]--;
                        shared_var[0]=0;
                        printf("\n");
                        sem_signal(&semaphores[0]);
                    }
                }
                shmdt(semaphores);
                shmdt(shared_var);
                exit(0);
            }
            else if(i==2)
            {
                while(1)
                {
                    sem_wait(&semaphores[2]);
                    if(shared_var[1]<=0)
                        break;
                    printf("C");
                    fflush(stdout);
                    if(shared_var[0]==0)
                    {
                        shared_var[0]=1;
                        sem_signal(&semaphores[2]);
                    }
                    else
                    {
                        sem_signal(&semaphores[0]);
                    }
                }
                shmdt(semaphores);
                shmdt(shared_var);
                exit(0);
            }
        }
    }
    for(int i=0;i<3;i++)
    {
        waitpid(p_arr[i],&status,0);
    }
    shmdt(semaphores);
    shmdt(shared_var);
    shmctl(shm_id,IPC_RMID,NULL);
    shmctl(shm_id1,IPC_RMID,NULL);
    return 0;
}