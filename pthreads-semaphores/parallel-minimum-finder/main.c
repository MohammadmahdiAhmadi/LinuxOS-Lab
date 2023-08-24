#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#define SIZE 8


int A[SIZE];
sem_t sem[SIZE];
int stride = SIZE / 2;

void* findMin(void * id)
{
	int i = (int)id;

	if (A[i + stride] < A[i])
		A[i] = A[i + stride];

	pthread_exit(NULL);
}

int main()
{
	srand(time(NULL));
	for (int i=0; i < SIZE; i++) {
		A[i] = rand() % 100;
	}

	printf("A ->");
	for (int i=0; i < SIZE; i++)
		printf(" %d", A[i]);
	printf("\n");

	for (int i=0; i < SIZE; i++)
		sem_init(&sem[i], 0, 1);

	while (stride > 0) {
		pthread_t threads[stride];

		for (int i=0; i < stride; i++)
			pthread_create(&threads[i], NULL, findMin, (void *)i);
	
		for (int i=0; i < stride; i++)
			pthread_join(threads[i], NULL);

		stride /= 2;
	}

        printf("Min value: %d\n", A[0]);

        return 0;
}
