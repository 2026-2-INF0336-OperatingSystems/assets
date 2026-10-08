/*
  Program: POSIX MutEx

  # Compile:
    gcc -o <my-program>.out <nome-programa>.c -lpthread

 @author: Aldo Diaz, PhD, EE
                   Instituto de Informatica - INF
                   Universidade Federal de Goias - UFG
  Copyright Aldo Diaz, 2021
*/

#include <pthread.h>

int main(int argc, char *argv[]) {
    pthread_mutex_t mutex; // MutEx declaration (POSIX Pthreads API)

    // Create and initiliaze MutEx
    pthread_mutex_init(&mutex, NULL);

    // Acquire MutEx
    pthread_mutex_lock(&mutex);

    // Critical section

    // Release MutEx
    pthread_mutex_unlock(&mutex);

    // Delete MutEx
    pthread_mutex_destroy(&mutex);

    return 0;
}

