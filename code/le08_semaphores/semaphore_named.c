/*
  Program: POSIX named semaphore

  # Compile:
      gcc -o <my_program>.out <my_program>.c -lpthread

  @author: Aldo Diaz, PhD, EE
                    Institute of Informatics - INF
                    Federal University of Goias - UFG
                    2021
*/

#include <fcntl.h>
#include <semaphore.h>

int main(int argc, char *argv[]) {
    sem_t *sem; // Semaphore in POSIX Pthreads API

    // Create and init semaphore to the value of 1
    sem = sem_open("SEM", O_CREAT, 0666, 1);

    // Get semaphore
    sem_wait(sem);

    /*
    Critical section
    */

    // Release semaphore
    sem_post(sem);

    // Free semaphore
    sem_destroy(sem);

    return 0;
}

