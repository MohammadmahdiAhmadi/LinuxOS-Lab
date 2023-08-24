#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
	char buffer[256]={0};
	sprintf(buffer, "%s", "t,17,22,12");
	int fd=open("/dev/banknode", O_CREAT | O_TRUNC | O_RDWR);
	write(fd, buffer, strlen(buffer));
	close(fd);
	return 0;
}
