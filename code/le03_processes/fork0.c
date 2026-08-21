/*
  Test with fork and address spaces
*/ 

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

volatile int s = 0; // shared variable

int main() {
    printf("Before fork\n");

    if(fork() == 0) {
        s = 0;
        printf("Child process, &s = %p, s = %d\n", (void*) &s, s);
    } else {
        s = 1;
        printf("Parent process,   &s = %p, s = %d\n", (void*) &s, s);
    }

    return 0;
}

