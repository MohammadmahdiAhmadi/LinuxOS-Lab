#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <stdlib.h>

struct myTask {
        char name[20];
        pid_t pid;
};

int main(void) {
	struct myTask * tasksList = (struct myTask *) malloc(100 * sizeof(struct myTask));

	while (1){
		int ret = syscall(548, tasksList);
		for(int i=0; i<ret; i++) {
			printf("Task name: %s \t task pid: %d\n", tasksList[i].name, tasksList[i].pid);
		}
		fflush(stdout);
		sleep(2);
	}

	return 0;
}
