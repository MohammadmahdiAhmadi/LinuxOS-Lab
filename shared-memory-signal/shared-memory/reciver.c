#include "protocol.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

int main()
{
    int fd = shm_open(NAME, O_RDONLY, 0666);
    if (fd<0) {
        perror("shm_open()");
        return EXIT_FAILURE;
    }

    int size = sizeof(struct shmStruct) * 2;

    struct shmStruct *shmArr = (struct shmStruct*)mmap(0, size, PROT_READ, MAP_SHARED, fd, 0); // the error when i add PROT_WRITE is -> mmap(): Permission Denid 
    if(shmArr == (void *)-1){
        perror("mmap()");
        return EXIT_FAILURE;
    }

    printf("reciver address: %p\n", shmArr);

    for (int i = 0; i < NUM; i++) {
        printf("num%d: str value is %s, arr value is %d\n", i, shmArr[0].str, shmArr[0].arr[i]);
    }
    for (int i = 0; i < NUM; i++) {
        printf("num%d: str value is %s, arr value is %d\n", i, shmArr[1].str, shmArr[1].arr[i]);
    }

    munmap(shmArr, size);

    close(fd);

    // delete file
    shm_unlink(NAME);
    return EXIT_SUCCESS;
}
