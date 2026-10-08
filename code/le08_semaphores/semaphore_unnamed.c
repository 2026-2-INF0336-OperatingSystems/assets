/*
  Program: POSIX unnamed semaphore

  # Compile:
      gcc -o <my_program>.out <my_program>.c -lpthread

  @author: Aldo Diaz, PhD, EE
                    Institute of Informatics - INF
                    Federal University of Goias - UFG
                    2021
*/

#include <semaphore.h>

int main(int argc, char *argv[]) {
    sem_t sem; // Semaphore in POSIX Pthreads API

    // Create and init semaphore to the value of 1
    sem_init(&sem, 0, 1); // First flag <- 0: resource shared locally; Second flag <- 0: Semaphore's initial value
    
    // Get semaphore
    sem_wait(&sem);

    /*
    Critical section
    */

    // Free semaphore
    sem_post(&sem);

    /* Eliminar Semaforo */
    sem_destroy(&sem);

  return 0;
}
