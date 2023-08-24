#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "protocol.h"


int main()
{
    int fd = shm_open(NAME, O_CREAT | O_EXCL | O_RDWR, 0600);
    if (fd<0) {
        perror("shm_open()");
        return EXIT_FAILURE;
    }
    
    int size = sizeof(struct shmStruct) * 2;

    ftruncate(fd, size);

    struct shmStruct *shmArr = (struct shmStruct*)mmap(0, size, PROT_READ | PROT_WRITE,
     MAP_SHARED, fd, 0);
    if(shmArr == (void *)-1){
        perror("mmap()");
        return EXIT_FAILURE;
    }
    
    printf("sender address: %p\n", shmArr);

    // write my name and my firend name in structs
    strcat(shmArr[0].str, "MohammadMahdi");
    strcat(shmArr[1].str, "Amir");

    // write random number in array of struct
    srand(time(0));
    for (int i = 0; i < NUM; i++) {
	int r = rand()%5 + 1;
	shmArr[0].arr[i] = r;
	shmArr[1].arr[i] = r;
    }

    munmap(shmArr, size);

    close(fd);
    return EXIT_SUCCESS;
}
