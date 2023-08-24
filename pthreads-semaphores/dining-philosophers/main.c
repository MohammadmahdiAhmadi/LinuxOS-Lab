#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#define N 5


int phil[N] = {0, 1, 2, 3, 4};
int chopsticks[N] = {0, 0, 0, 0, 0};
sem_t sem_chopsticks[N];

int LEFT(int phil_id) {
        return (phil_id + 1) % N;
}

int RIGHT(int phil_id) {
        return (phil_id) % N;
}

void think(int phil_id) {
        printf("phil %d is thinking ...\n", phil_id);
        sleep(3);
}

int can_eat(int phil_id) {
        return (chopsticks[LEFT(phil_id)] + chopsticks[RIGHT(phil_id)]) == 0;
}

void eat(int phil_id) {
        int l = LEFT(phil_id);
        int r = RIGHT(phil_id);

        sem_wait(&sem_chopsticks[l]);
        chopsticks[l] = 1;
        sleep(1);
        sem_wait(&sem_chopsticks[r]);
        chopsticks[r] = 1;

        printf("phil %d is eating ...\n", phil_id);
        sleep(3);

        chopsticks[l] = 0;
        sem_post(&sem_chopsticks[l]);
        chopsticks[r] = 0;
        sem_post(&sem_chopsticks[r]);

}

void* philosopher(void * id)
{
    int* phil_id = id;
    while (1) {
        think(*phil_id);
        while(!can_eat(*phil_id));
        eat(*phil_id);
    }
}

int main()
{
    pthread_t thread_id[N];

    for (int i = 0; i < N; i++)
        sem_init(&sem_chopsticks[i], 0, 1);

    for (int i = 0; i < N; i++) {
        pthread_create(&thread_id[i], NULL, philosopher, &phil[i]);
    }

    for (int i = 0; i < N; i++) {
	    pthread_join(thread_id[i], NULL);
    }

    return 0;
}
