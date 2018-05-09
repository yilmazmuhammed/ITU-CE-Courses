/*
 * Compile this command: 
 * $ gcc -pthread threads.c
 *
 */



#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

/*
int pthread_create(
	pthread_t *thread, 					// Pointer to the thread to be created.
	const pthread_attr_t *attr, 		// Pointer to attiributes of the thread to be created. 
	void*(*start_routine)(void*), 		// Pointer to the routine that will start the thread
	void *arg 							// Pointer to the arguments for the start routine
	);
*/

void *print_message_function(void *ptr){
	char *message;
	message = (char*) ptr;
	printf("\n %s \n",message );
	// terminating thread
	pthread_exit(NULL);
}




int main(int argc, char *argv[])
{
	pthread_t thread1, thread2, thread3;
	char *message1 = "Hello";
	char *message2 = "World";
	char *message3 = "!...";


	if(pthread_create(&thread1, NULL, print_message_function, (void *)message1)){
		printf("pthread_create1 failure\n");
		exit(-1);
	}
	if(pthread_create(&thread2, NULL, print_message_function, (void *)message2)){
		printf("pthread_create2 failure\n");
		exit(-1);
	}
	if(pthread_create(&thread3, NULL, print_message_function, (void *)message3)){
		printf("pthread_create3 failure\n");
		exit(-1);
	}
	pthread_exit(NULL);

	return 0;
}
