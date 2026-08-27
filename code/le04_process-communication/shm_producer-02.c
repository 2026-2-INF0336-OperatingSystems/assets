/*
  Program: Use of shared memory in POSIX systems

  This the producer process that writes to the shared memory region

  # Compile:
      gcc -o <my-program>.out <my-program>.c -lrt

  @adapted_from: Figure 3.16
  Operating System Concepts - Tenth Edition
  Silberschatz, Galvin, and Gagne

  @author: Aldo Diaz, PhD, EE
           Instituto de Informatica - INF
           Universidade Federal de Goias - UFG
  Copyright Aldo Diaz, 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>

int main() {
    // Size of the shared memory object (in bytes)
    const int SIZE = 4096;
    // Name of the shared memory object
    const char *name = "shared-mem";
    // strings written to the shared memory
    const char *message0= "Estudar Sistemas Operacionais\n";
    const char *message1= "e bom demais!\n";

    // File descriptor of the shared memory
    int shm_fd;
    // Pointer to the shared memory object
    void *ptr;

    // Create the shared memory object
    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    if(shm_fd == -1) {
        fprintf(stderr, "Failed to open shared memory\n");
        exit(-1);
    }

    // Set shared memory object size
    ftruncate(shm_fd, SIZE);

    // Map the shared memory object into the process address space
    ptr = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if(ptr == MAP_FAILED) {
        fprintf(stderr, "Failed to map shared memory\n");
        return -1;
    }

    // Write to the shared memory object
    sprintf(ptr, "%s", message0);
    ptr += strlen(message0);
    sprintf(ptr, "%s", message1);
    ptr += strlen(message1);

    return 0;
}

