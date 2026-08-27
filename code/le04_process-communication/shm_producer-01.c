/*
  Simple program demonstrating shared memory in POSIX systems.
 
  This is the producer process that writes to the shared memory region (Figure 3.16).

  To compile, enter:
      gcc -o producer.out producer.c -lrt
 
  @author: Silberschatz, Galvin, and Gagne
  Operating System Concepts  - Tenth Edition
  Copyright John Wiley & Sons - 2018
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
    // shared-memory object size (in bytes)
    const int SIZE = 4096;
    // shared-memory object name
    const char *name = "OS";
    // strings written to shared-memory
    const char *message0= "Estudar Sistemas Operacionais\n";
    const char *message1= "e bom demais!\n";

    // shared-memory file descriptor
    int shm_fd;
    // pointer to shared-memory object
    void *ptr;

    // Create the shared-memory object
    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    if(shm_fd == -1) {
        printf("Shared memory open failed\n");
        exit(-1);
    }

    // Set the size of shared-memory object
    ftruncate(shm_fd, SIZE);

    // Map the shared-memory object in the address space of the process
    ptr = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if(ptr == MAP_FAILED) {
        printf("Shared memory map failed\n");
        return -1;
    }

    // Write to the shared-memory object
    sprintf(ptr, "%s", message0);
    ptr += strlen(message0);
    sprintf(ptr, "%s", message1);
    ptr += strlen(message1);

    return 0;
}

