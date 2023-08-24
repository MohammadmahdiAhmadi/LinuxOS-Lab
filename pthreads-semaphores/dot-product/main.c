#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#define SIZE 20
#define THREADS 5


int vect_A[SIZE];
int vect_B[SIZE];
int product = 0;
sem_t sem1;

void *dotProduct(void * id)
{
	int i = (int)id;
	int myProduct = 0; 

	for (i; i < SIZE; i += THREADS)
        	myProduct += (vect_A[i] * vect_B[i]);

	sem_wait(&sem1);
	product += myProduct;
	sem_post(&sem1);

	pthread_exit(NULL);
}

int main()
{
	srand(time(NULL));
	for (int i=0; i < SIZE; i++) {
		vect_A[i] = rand() % 2;
		vect_B[i] = rand() % 2;
	}

	printf("vect_A ->");
	for (int i=0; i < SIZE; i++)
		printf(" %d", vect_A[i]);
	printf("\nvect_B ->");
	for (int i=0; i < SIZE; i++)
		printf(" %d", vect_B[i]);
	
	printf("\n");

	sem_init(&sem1,0,1);
	pthread_t threads[THREADS];

	for (int i=0; i < THREADS; i++)
		pthread_create(&threads[i], NULL, dotProduct, (void *)i);
	
	for (int i=0; i < THREADS; i++)
		pthread_join(threads[i], NULL);

        printf("Dot product: %d\n", product);

        return 0;
}

