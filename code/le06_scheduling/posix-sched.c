/*
  Program: Scheduling in POSIX systems

  # Compile:
      gcc -o <my-program>.out <my-program>.c -lpthread

  @adapted_from: Figure 5.10
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
    int i, scope;
    pthread_t tid[NUM_THREADS];  // TID - Thread identifier
    pthread_attr_t attr; // Thread attributes

    // Set default thread attributes
    pthread_attr_init(&attr);

    // Get current scope
    if(pthread_attr_getscope(&attr, &scope) != 0)
        fprintf(stderr, "Unable to get scheduling scope\n");
    else {
        if(scope == PTHREAD_SCOPE_PROCESS)
	    printf("PTHREAD_SCOPE_PROCESS\n");
	else if(scope == PTHREAD_SCOPE_SYSTEM)
	    printf("PTHREAD_SCOPE_SYSTEM\n");
	else
	    fprintf(stderr, "Illegal scope value\n");
    }

    // Set scheduling algorithm from PCS to SCS
    if(pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM) != 0)
        fprintf(stderr, "Unable to set scheduling policy\n");

    // Thread creation
    for(i = 0; i < NUM_THREADS; i++)
        pthread_create(&tid[i], &attr, runner, NULL);

    // Wait for threads to finish
    for(i = 0; i < NUM_THREADS; i++)
        pthread_join(tid[i], NULL);
}

// Thread function definition
void *runner(void *param) {
    // Do something . . .
    printf("Hi, I'm the example thread\n");
    pthread_exit(0);
}

