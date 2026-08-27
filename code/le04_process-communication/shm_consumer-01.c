/*
  Simple program demonstrating shared memory in POSIX systems.
 
   This is the consumer process (Figure 3.18)

  To compile, enter:
      gcc -o consumer.out consumer.c -lrt

  @author: Gagne, Galvin, Silberschatz
  Operating System Concepts - Tenth Edition
  Copyright John Wiley & Sons - 2018
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main() {
    // shared-memory object size (in bytes)
    const int SIZE = 4096;
    // shared-memory object name
    const char *name = "OS";
    // shared-memory file descriptor
    int shm_fd;
    // pointer to shared-memory object
    void *ptr;

    // open the shared-memory object
    shm_fd = shm_open(name, O_RDONLY, 0666);
    if(shm_fd == -1) {
        printf("Shared memory open failed\n");
        exit(-1);
    }

     // Map the shared-memory object in the address space of the process
    ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
    if(ptr == MAP_FAILED) {
        printf("Shared memory map failed\n");
        exit(-1);
    }

    // Read from the shared-memory object
    printf("%s", (char *)ptr);

    // Remove the shared-memory object
    if(shm_unlink(name) == -1) {
        printf("Error removing %s\n",name);
        exit(-1);
    }

    return 0;
}

