#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAXCHILD 5

void task(int id);

int main()
{
	pid_t pid;
	pid_t childs_id[MAXCHILD];

	int i;
	for(i=0; i<MAXCHILD; i++) {
		pid = fork();
		if(pid == 0){
			task(i);
		} else {
			childs_id[i] = pid;
		}
	}

	if(pid != 0) {
		int child_d;
		while(1) {
			sleep(5);
			int i;
			for(i=0; i<MAXCHILD; i++) {
				int status = 0;
				child_d = waitpid(childs_id[i], &status, WNOHANG);
				if(child_d == 0) {
					printf("child %d is still alive\n", childs_id[i]);
				} else if(child_d < 0) {
					printf("error. no specific child to wait for\n");
				} else {
					printf("running pid %d again with task number %d ...\n", childs_id[i], i);
					childs_id[i] = fork();
					if(childs_id[i] == 0) {
						task(i);
					}
				}
			}
		}
	}

	return 0;
}

void task(int id){
	srand(time(0)+getpid());

	int rand5;
	rand5 = (rand() % 5) + 1; // between 1, 5
	sleep(rand5);

	printf("Task %d has been done by child %d in %d seconds\n", id, getpid(), rand5);

	exit (0);
}
