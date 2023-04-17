#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <unistd.h>

#define N 5 // number of philosophers
#define MAX_TIME 5 // maximum time a philosopher can spend thinking (in seconds)

pthread_t philosophers[N];
pthread_mutex_t forks[N];
sem_t waiter;

int left(int i) { return i; } // index of philosopher to the left
int right(int i) { return (i + 1) % N; } // index of philosopher to the right

void think(int i) {
    int thinking_time = rand() % MAX_TIME;
    printf("Philosopher %d is thinking for %d seconds\n", i, thinking_time);
    sleep(thinking_time); // simulate thinking for random time
}

void eat(int i) {
    printf("Philosopher %d is eating\n", i);
    sleep(rand() % 3); // simulate eating for random time
}

void* philosopher(void* arg) {
    int i = *(int*)arg;
    struct timespec time_to_wait;
    while (1) {
        think(i);
        sem_wait(&waiter); // acquire the waiter semaphore
        pthread_mutex_lock(&forks[left(i)]); // pick up left fork
        pthread_mutex_lock(&forks[right(i)]); // pick up right fork
        sem_post(&waiter); // release the waiter semaphore
        eat(i);
        pthread_mutex_unlock(&forks[left(i)]); // put down left fork
        pthread_mutex_unlock(&forks[right(i)]); // put down right fork
        time_to_wait.tv_sec = rand() % MAX_TIME;
        time_to_wait.tv_nsec = 0;
        nanosleep(&time_to_wait, NULL); // sleep for random time before starting over
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    int i;
    int indices[N];
    sem_init(&waiter, 0, N-1); // initialize waiter semaphore to N-1
    for (i = 0; i < N; i++) {
        pthread_mutex_init(&forks[i], NULL); // initialize fork mutexes
        indices[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &indices[i]); // create philosopher threads
    }
    for (i = 0; i < N; i++) {
        pthread_join(philosophers[i], NULL); // wait for philosopher threads to exit
    }
    sem_destroy(&waiter); // destroy semaphore
    for (i = 0; i < N; i++) {
        pthread_mutex_destroy(&forks[i]); // destroy mutexes
    }
    return 0;
}