/*
  Program: Use of shared memory in POSIX systems

  This is the consumer process

  # Compile:
      gcc -o <my-program>.out <my-program>.c -lrt

  @adapted_from: Figure 3.18
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
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main() {
    // Size of the shared memory object (in bytes)
    const int SIZE = 4096;
    // Name of the shared memory object
    const char *name = "shared-mem";
    // File descriptor of the shared memory 
    int shm_fd;
    // Pointer to the shared memory object
    void *ptr;

    // Open the shared memory object
    shm_fd = shm_open(name, O_RDONLY, 0666);
    if(shm_fd == -1) {
        fprintf(stderr, "Failed to open shared memory\n");
        exit(-1);
    }

     // Map the shared memory object into the process address space
    ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
    if(ptr == MAP_FAILED) {
        fprintf(stderr, "Failed to map shared memory\n");
        exit(-1);
    }

    // Read the shared memory object
    printf("%s", (char *)ptr);

    // Remove the shared memory object
    if(shm_unlink(name) == -1) {
        fprintf(stderr, "Error removing %s\n", name);
        exit(-1);
    }

    return 0;
}

