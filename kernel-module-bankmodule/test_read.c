#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
	char readBuffer[128]={0};
	int fd=open("/dev/banknode", O_RDONLY);
	read(fd,readBuffer, 128);
	fprintf(stdout,"%s\n",readBuffer);
	close(fd);
	return 0;
}
