/*
  Program: Use of API POSIX pthread

  This program implements a summation function using threads.
  
 # Compile:
 gcc -o <my-program>.out <my-program>.c -lpthread

 @adapted_from: Figure 4.11
 Operating System Concepts - Tenth Edition
 Silberschatz, Galvin, and Gagne

 @author: Aldo Diaz, PhD, EE
                   Institute of Informatics - INF
                   University of Goias  - UFG
                   2021
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum; // Data shared by threads

void *summation(void *param); // Thread function

int main(int argc, char *argv[]) {
    pthread_t tid; // TID - Thread identifier
    pthread_attr_t attr; // Thread attributes

    // Input validation
    if(argc != 2) {
        fprintf(stderr, "Sintax: <my-program.out> <integer-number>\n");
        exit(-1);
    }

    if(atoi(argv[1]) < 0) {
        fprintf(stderr, "Argument %d must be non-negative\n", atoi(argv[1]));
        exit(-1);
    }

    // 1. Define threads with default attributes
    pthread_attr_init(&attr);

    // 2. Create threads
    pthread_create(&tid, &attr, summation, argv[1]);

    // 3. Wait for threads to finish
    pthread_join(tid, NULL);

    printf("Sum: %d\n", sum);
}

// Thread function
void *summation(void *param) {
    int upper = atoi(param);
    sum = 0;

    if(upper > 0) {
        for(int k=1; k<=upper; k++)
            sum += k;
    }

    pthread_exit(0);
}

