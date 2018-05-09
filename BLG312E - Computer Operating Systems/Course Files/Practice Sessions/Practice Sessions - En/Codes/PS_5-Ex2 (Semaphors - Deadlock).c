#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>	// semaphore için
#include <sys/sem.h>	// semaphore için
#include <sys/types.h>	// semaphore için
#include <signal.h>		// handling signals için	// s i g a c t i o n
#include <sys/types.h>	// handling signals için

#define SEMKEY_A 1
#define SEMKEY_B 2
#define SEMKEY_C 3




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
	int semA, semB, semC, children[2], f=1, i, myOrder;

	// creating 2 child processes
	for(i = 0; i<2; ++i)
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
	if(f!=0)
	{
		printf("PARENT is starting to CREATE RECOURCES .......\n");
		
		// creating 3 semaphore and setting two of them as 1 and the other as 0
		semA = semget(SEMKEY_A,1,0700|IPC_CREAT);
		semctl(semA, 0, SETVAL, 1);
		semB = semget(SEMKEY_B,1,0700|IPC_CREAT);
		semctl(semB, 0, SETVAL, 1);
		semC = semget(SEMKEY_C,1,0700|IPC_CREAT);
		semctl(semC, 0, SETVAL, 0);
		sleep(2);
		printf("PARENT is starting CHILD Processes .......\n");
		
		//sending the signal 12 to all child process
		for (i = 0; i < 2; ++i)
			kill(children[i], 12);
		
		// decrease semaphore value by 10 (ie. wait for all childs to increase semaphore value)
		sem_wait(semC,2);
		printf("PARENT: Child processes has done, resources are removed back.\n");
		// remove the semaphore set identified with sem_id
		semctl(semA, 0, IPC_RMID, 0);
		semctl(semB, 0, IPC_RMID, 0);
		semctl(semC, 0, IPC_RMID, 0);
		exit(0);
	}
	//child processes
	else
	{
		myOrder = i;
		printf("CHILD %d: waiting permission from PARENT ....\n", myOrder);

		// wait for a signal
		pause();
		
		//returning the sem_id associated with SEMKEY_A, SEMKEY_B, and SEMKEY_C
		semA = semget(SEMKEY_A,1,0);
		semB = semget(SEMKEY_B,1,0);
		semC = semget(SEMKEY_C,1,0);
		printf("CHILD %d has permission from PARENT, is starting ...\n",myOrder );

		if(myOrder == 0){
			printf("CHILD %d: DECREASING sem A.\n",myOrder );
			sem_wait(semA, 1);
			sleep(1);
			printf("CHILD %d: sem A is completed, DECREASING sem B.\n", myOrder);
			sem_wait(semB, 1);
			printf("CHILD %d: I am in the CRITICAL REGION.\n",myOrder );
			sleep(5);	//Critical region operations
			//increase all the semaphore values by 1
			sem_signal(semB,1);
			sem_signal(semA, 1);
			sem_signal(semC, 1);
		}	
		else if(myOrder == 1){
			printf("CHILD %d: DECREASING sem B.\n",myOrder );
			sem_wait(semB, 1);
			sleep(1);
			printf("CHILD %d: sem B is completed, DECREASING sem A.\n", myOrder);
			sem_wait(semA, 1);
			printf("CHILD %d: I am in the CRITICAL REGION.\n",myOrder );
			sleep(5);	//Critical region operations
			//increase all the semaphore values by 1
			sem_signal(semA,1);
			sem_signal(semB, 1);
			sem_signal(semC, 1);
		}
	}

	return 0;
}