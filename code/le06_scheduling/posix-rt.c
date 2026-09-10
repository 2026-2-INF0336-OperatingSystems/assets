/*
  Program: Threads exemplifying real-time Pthread scheduling

  # Compile:
      gcc -o <my-program>.out <my-program>.c -lpthread

  @adapted_from: Figure 5.25
  Operating System Concepts - Tenth Edition
  Silberschatz, Galvin, and Gagne

  @author: Aldo Diaz, PhD, EE
                    Instituto de Informatica - INF
                    Universidade Federal de Goias - UFG
  Copyright Aldo Diaz, 2021
*/

#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS  5 // Number of threads to create

// Thread function declaration 
void *runner(void *param);

int main(int argc, char *argv[]) {
    int i, policy;
    pthread_t tid[NUM_THREADS];  // TID - Thread identifier
    pthread_attr_t attr; // Thread attributes

    // Set default thread attributes
    pthread_attr_init(&attr);

    // Get current scheduling policy
    if(pthread_attr_getschedpolicy(&attr, &policy) != 0)
        fprintf(stderr, "Unable to get scheduling policy\n");
    else {
        if(policy == SCHED_OTHER)
	    printf("SCHED_OTHER\n");
	else if(policy == SCHED_RR)
	    printf("SCHED_RR\n");
	else if(policy == SCHED_FIFO)
            printf("SCHED_FIFO\n");
    }

    // Set scheduling policy (FIFO, RT, OTHER)
    if(pthread_attr_setschedpolicy(&attr, SCHED_OTHER) != 0)
        fprintf(stderr, "Unable to set scheduling policy\n");

    // Create threads
    for(i = 0; i < NUM_THREADS; i++)
        pthread_create(&tid[i], &attr, runner, NULL);

    // Wait for threads to complete
    for(i = 0; i < NUM_THREADS; i++)
        pthread_join(tid[i], NULL);
}

// Thread function definition
void *runner(void *param) {
    // Do something here . . .
    printf("We are the real-time threads\n");
    pthread_exit(0);
}

