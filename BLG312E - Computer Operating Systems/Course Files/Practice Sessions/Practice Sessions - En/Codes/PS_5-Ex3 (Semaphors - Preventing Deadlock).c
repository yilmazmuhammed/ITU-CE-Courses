#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>	// semaphore için
#include <sys/sem.h>	// semaphore için
#include <sys/types.h>	// semaphore için
#include <signal.h>		// handling signals için	// s i g a c t i o n
#include <sys/types.h>	// handling signals için
#include <sys/errno.h>

#define SEMKEY_AB 5
#define SEMKEY_C 6

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

// increment operation usşng two semaphores
void sem_multi_signal(int semid, int val, int nsems)
{
	struct sembuf semaphore[2];
	int i;
	for (i = 0; i < nsems; ++i){
		semaphore[i].sem_num = i;
		semaphore[i].sem_op = val;
		semaphore[i].sem_flg = 1;
	}

	// TWO Operations are performed on SAME SEMAPHORE SET
	semop(semid, semaphore, 2);
	for (i = 0; i < nsems; ++i){
		printf("SIGNAL: SEM %d IS NOW: .... %d\n",i, semctl(semid, i, GETVAL, 0));	
	}
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

// decrement operation using two semaphores
void sem_multi_wait(int semid, int val, int nsems)
{
	struct sembuf semaphore[2];
	int i;
	for (i = 0; i < nsems; ++i){
		semaphore[i].sem_num = i;
		semaphore[i].sem_op = (-1*val);
		semaphore[i].sem_flg = 1;
	}

	// TWO Operations are performed on SAME SEMAPHORE SET
	semop(semid, semaphore, 2);
	
	for (i = 0; i < nsems; ++i){
		printf("WAIT: SEM %d is NOW: .... %d\n",i, semctl(semid, i, GETVAL, 0));	
	}
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
	int semAB, semC, children[2], f=1, i, myOrder;

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
	if(f!=0){
		printf("PARENT is starting to CREATE RECOURCES .......\n");
		
		// creating a set of 2 semaphore and settings their values as 1
		semAB = semget(SEMKEY_AB,2,0700|IPC_CREAT);
		if(semAB == -1)
			printf("SEMGET ERROR on SEM SET, Error code: %d\n",errno );
		if(semctl(semAB, 0, SETVAL, 1) == -1)
			printf("SEMCTL ERROR on SEM A, Error  Code: %d\n", errno );
		if(semctl(semAB, 1, SETVAL, 1) == -1)
			printf("SEMCTL ERROR on SEM B, Error  Code: %d\n", errno );
		printf("PARENT: SEM A is NOW ..... %d\n",semctl(semAB, 0, GETVAL, 0));
		printf("PARENT: SEM B is NOW ..... %d\n",semctl(semAB, 1, GETVAL, 0));

		// creating another semaphore and setting its value as 0
		semC = semget(SEMKEY_C,1,0700|IPC_CREAT);
		semctl(semC, 0, SETVAL, 0);
		printf("PARENT: SEM C is NOW ... %d\n",semctl(semC, 0, GETVAL, 0) );
		
		sleep(2);

		printf("PARENT is starting CHILD Processes .......\n");
		
		//sending the signal 12 to all child process
		for (i = 0; i < 2; ++i)
			kill(children[i], 12);
		sleep(5);

		// decrease semaphore value by 10 (ie. wait for all childs to increase semaphore value)
		sem_wait(semC,2);
		
		printf("PARENT: SEM C is NOW ... %d\n",semctl(semC, 0, GETVAL, 0));
		printf("PARENT: Child processes has done, resources are removed back.\n"); 
		
		// remove the semaphore set identified with sem_id
		semctl(semC, 0, IPC_RMID, 0);
		semctl(semAB, 0, IPC_RMID, 0);
		exit(0);
	}
	//child processes
	else
	{
		myOrder = i;
		printf("CHILD %d: waiting permission from PARENT ....\n", myOrder);

		// wait for a signal
		pause();
		
		//returning the sem_ids associated with SEMKEY_AB and SEMKEY_C
		semAB = semget(SEMKEY_AB,2,0);
		semC = semget(SEMKEY_C,1,0);

		printf("CHILD %d has permission from PARENT, is starting ...\n",myOrder );
		
		printf("CHILD %d: DECREASING sem AB.\n",myOrder );
		sem_multi_wait(semAB, 1, 2);
		
		printf("CHILD %d: I am in the CRITICAL REGION.\n",myOrder );
		sleep(5);

		sem_multi_signal(semAB, 1, 2);
		sem_signal(semC, 1);

	
	}

	return 0;
}