#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAXCHILD 5
#define MAXIMUM 100
#define F_PATH "q2.pipe"

void task(int* fd);

int main()
{
	int fd[MAXCHILD][2];
	pid_t pid;

	for(int i=0; i<MAXCHILD; i++) {
		pipe(fd[i]);
		pid = fork();
		if(pid == 0){
			task(fd[i]);
		}
	}

	if(pid != 0) { // only when in parent
		int total = 0;
		int res;
		while(total < MAXIMUM){
			for(int i=0; i<MAXCHILD; i++){
				if(read(fd[i][0], &res, sizeof(res))){
					printf("res=%d\n", res);
					total += res;
				}
			}
		}
		printf("total is: %d\n", total);
		// Killing all childs
		kill(0, SIGKILL);
		exit(0);
	}

	return 0;
}

void task(int* fd){
	srand(time(0)+getpid());
	while(1){
		int rand5;
		rand5 = (rand() % 5) + 1; // between 1, 5
		sleep(rand5);

		write(fd[1], &rand5, sizeof(rand5));
		printf("in childs loop, sleep time was: %d seconds\n", rand5);
	}
}
