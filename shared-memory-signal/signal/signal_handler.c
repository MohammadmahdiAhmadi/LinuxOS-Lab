/*
this program initializes a signal action
assigns a handler to this action and waits for SIGINT (ctrl+c) to be handled
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

// "handler1" is handler function for action1
void handler1(int signo)
{
	switch(signo)
	{
		case SIGALRM:
		printf("I recived alarm\n");
		break;
	}
}


int main()
{
	//initializing sigaction structure
	struct sigaction action1;
	action1.sa_handler = handler1;
	action1.sa_flags = 0;
	sigaction(SIGALRM,(struct sigaction *) &action1,NULL);

	alarm(5);

	printf("Process run by pid:%d\n", getpid());

	//runnign forever, while process is sensitive to SIGINT
	while(1){
		printf("I am alive!\n");
		sleep(1);
	}

	return 0;
}

