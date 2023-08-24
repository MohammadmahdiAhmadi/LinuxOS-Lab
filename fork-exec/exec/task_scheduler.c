#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <time.h>

int main(int argc, char *argv[])
{
	printf("Date, Time, Execution Time, r\n");
	while(1){
		srand(time(0));
		int r = (rand() % 5) + 1;
		
		char buffer[50];
		sprintf(buffer, "%d", r);
		
		char *const permlist[] = {"./a.out", buffer, NULL};

		struct timeval start, stop;
		gettimeofday(&start, NULL);

		pid_t pid = fork();
		if(pid == 0) {
			execv("./a.out", permlist);			
		}
		int status;
		wait(&status);

		gettimeofday(&stop, NULL);
		long sec = stop.tv_sec - start.tv_sec;
		float us = stop.tv_usec - start.tv_usec;
		long elapsed = sec * 1000 + us/1000.0;

		time_t t = time(NULL);
		struct tm tm = *localtime(&t);

		printf("%d-%02d-%02d, %02d:%02d, %d, %d\n", tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min, elapsed, r);
		
	}

	return 0;
}
