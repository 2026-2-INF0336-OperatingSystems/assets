/*
  Program: Multithread synchronization with POSIX unnamed semaphores 

  # Compile:
      gcc -o <my_program>.out <my_program>.c -lpthread

  @author: Aldo Diaz, PhD, EE
           Institute of Informatics - INF
           Federal University of Goias - UFG
           2021
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <semaphore.h>

#define NUM_THREADS   2

// Global variables
sem_t sem; // Semaphore in POSIX Pthreads API

// Thread function declarations
void *T0(void *param);
void *T1(void *param);

int main(int argc, char *argv[]) {
    pthread_t workers[NUM_THREADS]; // Thread IDs
    pthread_attr_t attr; // Thread attributes

    // Input parameters verification
    if(argc != 3) {
        fprintf(stderr, "Usage: <my_program> <integer_value> <integer_value>\n");
        return -1;
    }
    if(atoi(argv[1]) < 0 || atoi(argv[2]) < 0) {
        fprintf(stderr, "Arguments must be non-negative\n");
        return -1;
    }
    // Create and init a semaphore with the value of 0
    sem_init(&sem, 1, 0); // First flag <- 1: Resource shared between processes; Second flag <- 0: Semaphore's initial value

    // Set threads with default attributes
    pthread_attr_init(&attr);

    // Create threads
    pthread_create(&workers[0], &attr, T0, argv[1]);
    pthread_create(&workers[1], &attr, T1, argv[2]);

    // Wait for threads
    for(int i=0; i<NUM_THREADS; i++)
        pthread_join(workers[i], NULL);

    // Free semaphore
    sem_destroy(&sem);

    return 0;
}

// Thread function definitions
void *T0(void *param) {
    int upper = atoi(param);

    // Get semaphore
    sem_wait(&sem);

    // Critical Section
    fprintf(stdout, "I am T0: %d\n", upper);

    // Free semaphore
    sem_post(&sem);

    pthread_exit(0);
}

void *T1(void *param) {
    int upper = atoi(param);

    // Critical section
    fprintf(stdout, "I am T1: %d\n", upper);

    // Free semaphore
    sem_post(&sem);

    pthread_exit(0);
}

