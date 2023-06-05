#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <time.h>

void sem_wait(int *sem)
{
    while(__atomic_load_n(sem,__ATOMIC_SEQ_CST)<=0);
    __atomic_fetch_sub(sem,1,__ATOMIC_SEQ_CST);
}
void sem_signal(int *sem)
{
    __atomic_fetch_add(sem,1,__ATOMIC_SEQ_CST);
}
int main()
{
    srand(time(NULL));
    int shm_id1,shm_id2;
    int *semaphores,*shared;
    int sem_key=1011;
    int shared_var=1012;
    shm_id1=shmget(sem_key,sizeof(int)*2,IPC_CREAT|0666);
    shm_id2=shmget(shared_var,sizeof(int)*2,IPC_CREAT|0666);
    semaphores = (int*)shmat(shm_id1,NULL,0);
    shared=(int*)shmat(shm_id2,NULL,0);
    semaphores = (int*)shmat(shm_id1,NULL,0);
    semaphores[0]=1;//mutex
    semaphores[1]=1;//rw
    shared[0]=0;//readcount
    shared[1]=1;//container
    int pid = fork();
    if(pid==0)
    {
        //reader
        while(1)
        {
            sem_wait(&semaphores[0]);
            shared[0]++;
            if(shared[0]==1)
                sem_wait(&semaphores[1]);
            sem_signal(&semaphores[0]);
            printf("\nReader read %d\n",shared[1]);
            fflush(stdout);
            sem_wait(&semaphores[0]);
            shared[0]--;
            if(shared[0]==0)
                sem_signal(&semaphores[1]);
            sem_signal(&semaphores[0]);
            sleep(1);//read delay
        }
        shmdt(semaphores);
        shmdt(shared);
        exit(0);
    }
    while (1)
    {
        sem_wait(&semaphores[1]);
        shared[1] = rand()%100;
        printf("\nWriter wrote: %d\n",shared[1]);
        fflush(stdout);
        sem_signal(&semaphores[1]);
        sleep(4);//write delay
    }
    shmctl(shm_id1,IPC_RMID,NULL);
    shmctl(shm_id2,IPC_RMID,NULL);
    return 0;
}