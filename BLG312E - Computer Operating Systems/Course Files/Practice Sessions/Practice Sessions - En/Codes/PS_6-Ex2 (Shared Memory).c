#include <sys/shm.h>
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	// Allocate a Shared Memory Location
	int segment_id;
	const int shared_segment_size = 0x6400;
	segment_id = shmget(IPC_PRIVATE, shared_segment_size, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);

	// IPC_PRIVATE: shared memory cannot be accessed by other processes
	// IPC_CREAT: create the segment if it doesn’t already exist
	// IPC_EXCL: fail if segment already exists
	// S_IRUSR: read permission, owner
	// S_IWUSR: write permission, owner

	// Attach a Connection
	char* shared_memory;
	shared_memory = (char*) shmat(segment_id, 0, 0);
	printf("Shared memory attached address: %p\n",shared_memory);

	// Learn the segment size
	int segment_size;
	struct shmid_ds shmbuffer;
	shmctl(segment_id, IPC_STAT, &shmbuffer);
	segment_size = shmbuffer.shm_segsz;
	printf("Segment size is: %d\n", segment_size);

	// Write a String into the Shared Memory Location
	sprintf(shared_memory, "Hello, World.");

	// Detach Connection
	shmdt(shared_memory);

	// Make a Shared memory Connection to Another Adress
	shared_memory = (char*) shmat(segment_id, (void*) 0x5000000, 0);
	printf("Shared Memory New Connection Adress %p\n",shared_memory );

	// Read string from the Shared Memory Location
	printf("%s\n",shared_memory );

	// Detach Conncetion
	shmdt(shared_memory);

	// Remove the Shared Memory Segment
	shmctl(segment_id, IPC_RMID, 0);

	return 0;
}