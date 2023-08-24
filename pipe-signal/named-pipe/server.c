#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "myh.h"

int main()
{
	struct PipeS ps;
	int fd;

	// ceate pipe
	mkfifo(F_PATH, 0777);
	printf("runing server ...\n");

	while(1)
	{
		fd = open(F_PATH, O_RDONLY);
		read(fd, &ps, sizeof(ps));
		close(fd);
		
		int res = 0;
		if(ps.c == 'm') {
			res = ps.a*ps.b;
		} else if (ps.c == 'p') {
			res = ps.a+ps.b;
			res = pow(ps.a, ps.b);
		}

		fd = open(F_PATH, O_WRONLY);
		write(fd, &res, sizeof(res));
		close(fd);	
	}
	return 0;
}
