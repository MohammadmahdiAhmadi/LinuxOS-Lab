#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "myh.h"

int main()
{
	struct PipeS ps;
	int res;
	int fd;

	while(1)
	{
		printf("2 number, 1 command (for example 37m, 41p):\n");
		scanf("%d %d %c", &ps.a, &ps.b, &ps.c);

		fd = open(F_PATH, O_WRONLY);
		write(fd, &ps, sizeof(ps));
		close(fd);

		fd = open(F_PATH, O_RDONLY);
		read(fd, &res, sizeof(res));
		printf("result:%d\n", res);
		close(fd);	
	}
	return 0;
}
