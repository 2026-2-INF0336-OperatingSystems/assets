/*
  Example: Use of fork
  Q: How many processes will be created?
  Q: Can you think of a way to control the process creation more precisely?
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    fork();
    fork();
    fork();

    printf("PID = %d\n", getpid());

    return 1;
}

