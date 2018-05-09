#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>	// semaphore için
#include <sys/sem.h>	// semaphore için
#include <sys/types.h>	// semaphore için
#include <signal.h>		// handling signals için	// s i g a c t i o n
#include <sys/types.h>	// handling signals için

#define SEMKEY 8
int sem_id;


// increment operation
// TEMEL SEMAPHORE İŞLEMLERİ (ARTTIRMA)
void sem_signal(int semid, int val)
{
	struct sembuf semaphore;
	semaphore.sem_num = 0;
	semaphore.sem_op = val;
	semaphore.sem_flg = 1;	// relavive: add sem_op to value
	semop(semid, &semaphore, 1);
}

// decrement operation
// TEMEL SEMAPHORE İŞLEMLERİ (EKSİLTME)
void sem_wait(int semid, int val)
{
	struct sembuf semaphore;
	semaphore.sem_num = 0;
	semaphore.sem_op = (-1*val);
	semaphore.sem_flg = 1;	// relavive: add sem_op to value
	semop(semid, &semaphore, 1);
}

// signal_handling function
void mysignal(int signum)
{
	printf("Received signal with num=%d\n",signum );
}

void mysigset(int num)
{
	struct sigaction mysigaction;
	mysigaction.sa_handler = (void*) mysignal;
	// using the signal-catching function identified by sa_handler
	mysigaction.sa_flags = 0;
	// sigaction() system call is used to change the action taken by a process 
		//on receipt of a specific signal (specified with num)
	sigaction(num, &mysigaction, NULL);
}

int main(void)
{
	// signal handler with num=12
	mysigset(12);
	int f = 1, i , children[10];
	// creatşng 10 child processes
	for(i = 0; i<10; ++i)
	{
		if(f>0)
			f = fork();
		if (f == -1)
		{
			printf("Fork error...\n");
			exit(1);
		}
		if(f==0)
			break;
		else
			children[i] = f;
	}

	//parent process
	if(f>0)
	{
		// creatşing semaphore with key=SEMKEY
		sem_id = semget(SEMKEY, 1, 0700|IPC_CREAT);
		// setting value of the 0th semaphore of the set identified with sem_id to 0
		semctl(sem_id, 0, SETVAL, 0);
		sleep(1);
		//sending the signal 12 to all child process
		for (i = 0; i < 10; ++i)
			kill(children[i], 12);
		// decrease semaphore value by 10 (ie. wait for all childs to increase semaphore value)
		sem_wait(sem_id,10);
		printf("ALL CHILDREN HAS Finished...\n");
		// remove the semaphore set identified with sem_id
		semctl(sem_id, 0, IPC_RMID, 0);
		exit(0);
	}
	//child processes
	else
	{
		// wait for a signal
		pause();
		//returning the sem_id associated with SEMKEY
		sem_id = semget(SEMKEY,1,0);
		printf("I am a CHILD process created in %dth order. My PRODESS_ID: %d\n",i,getpid() );
		// getting value of the 0th semaphore of the set identified with sem_id
		printf("SEMAPHORE VALUE: %d\n",semctl(sem_id, 0, GETVAL, 0) );
		// increase semaphore value by 1
		sem_signal(sem_id,1);
	}

	return 0;
}