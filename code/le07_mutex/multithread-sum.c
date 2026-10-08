/*
  Program: Multi-thread sum

  Parameters:
    <param1>: Thread function type, 1: summation1, 2: summation2
    <param2>: Number of threads to create
    <param3>: Sum increment value

  # Compile:
    gcc -o <my-program>.out <my-program>.c -lpthread

  # Run:
  ./<my-program>.out <param1> <param2> <param3>

 @author: Aldo Diaz, PhD, EE
                   Institute of Informatics - INF
                   Federal University of Goias - UFG
  Copyright Aldo Diaz, 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Thread function declaration
void *summation1(void *param);
void *summation2(void *param);

// Global variables
int sum = 0;
pthread_mutex_t mutex; // MutEx (POSIX Pthreads API)

int main(int argc, char *argv[]) {
    int F = atoi(argv[1]); // Thread function to execute
    int N = atoi(argv[2]); // Number of threads
    int incSum = atoi(argv[3]); // Sum increment
    pthread_t tid[N]; // TID - Thread identifier
    pthread_attr_t attr; // Thread attributes
    
    // Input validation
    if(argc != 4) {
        fprintf(stderr, "Syntax: <my-program> <thread-function-type> <number-of-threads> <sum-increment>\n");
        return -1;
    }

    // Create and initialize MutEx
    pthread_mutex_init(&mutex, NULL);

    // Set threads with default attributes
    pthread_attr_init(&attr);

    // Thread function to run
    if(F==1) {
        // Create threads
        for(int i=0; i<N; i++)
            pthread_create(&tid[i], &attr, summation1, argv[3]);
    }
    else if(F==2) {
        // Create threads
        for(int i=0; i<N; i++)
            pthread_create(&tid[i], &attr, summation2, argv[3]);
    }
    else {
        fprintf(stderr, "Invalid thread function: \"1\" OR \"2\"\n");
	return -1;
    }

    // Wait threads to finish
    for(int i=0; i<N; i++)
        pthread_join(tid[i], NULL);

    printf("Increment: %d\n", incSum);
    if(F==1)
        printf("F1: Balance: %d\n", sum);
    else
        printf("F2: Balance: %d\n", sum);

    // Delete MutEx
    pthread_mutex_destroy(&mutex);

    return 0;
}

// Thread function definition
void *summation1(void *param) {
    int increment = atoi(param);

    // printf("I am Thread TID: %ld\n", pthread_self());

    sum = sum + increment;

    pthread_exit(0);
}

void *summation2(void *param) {
    int increment = atoi(param);

    // printf("I am Thread TID: %ld\n", pthread_self());

    // Acquire MutEx
    pthread_mutex_lock(&mutex);

    // Critical section
    sum = sum + increment;
    
    // Release MutEx
    pthread_mutex_unlock(&mutex);

    pthread_exit(0);
}


