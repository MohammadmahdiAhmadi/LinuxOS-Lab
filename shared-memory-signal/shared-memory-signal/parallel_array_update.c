#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>
#include <signal.h>
#include <sys/mman.h>
#define MAX_CHILD 5
#define ARRAY_SIZE 100

int isSIGUSR1 = 0;

void handler1(int signo)
{
	switch(signo)
	{
		case SIGUSR1:
			isSIGUSR1 = 1;
			printf("glob value changed to 1\n");
		break;
	}
}


int main()
{
	printf("Process run by pid:%d\n", getpid());

	//initializing sigaction structure
	struct sigaction action1;
	action1.sa_handler = handler1;
	action1.sa_flags = 0;
	sigaction(SIGUSR1, (struct sigaction *) &action1, NULL);

	// initial shared memory
	int size = ARRAY_SIZE*sizeof(int);
	void *data = mmap(0, size, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, 0, 0);
	if(data == (void*)-1) {
		perror("mmapp()");
		return EXIT_FAILURE;
	}
	
	// convert type
	int *a = (int*)data;

	// create childs
	pid_t childs[MAX_CHILD];
	for(int i=0; i<MAX_CHILD; i++) {
		childs[i] = fork();
		if(childs[i] == 0) {
			task(i, a);
		}
	}

	// initial array value
	for(int i=0; i<ARRAY_SIZE; i++)
		a[i] = i;

	usleep(100); // wait for creating childs completly
	
	// send signal to all childs
	for(int i=0; i<MAX_CHILD; i++) {
		kill(childs[i], SIGUSR1);
	}

	// wait until end of all child processes
	while(wait(NULL) > 0); 

	// print array
	for(int i=0; i<ARRAY_SIZE; i++) {
		printf("index %d: %d\t", i, a[i]);
	}

	return 0;
}

void task(int index, int *a) {
	while(1) {
		// wait for signal
		pause();

		// update array
		if(isSIGUSR1 == 1) {
			for(int i=index; i<ARRAY_SIZE; i+=MAX_CHILD){
				a[i] = (2 * a[i]) + 1;
			}
			exit(0);
		}
	}
}

