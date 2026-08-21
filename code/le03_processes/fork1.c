/*
  Program: Showing the PID of parent, child and grandparent processes

  # 1. Compile:
      gcc -o <my-program>.out <my-program>.c

  # 2. Run:
      ./<my-program>.out

  @author: Aldo Diaz, PhD, EE
           Instituto de Informatica - INF
           Universidade Federal de Goias - UFG
  Copyright Aldo Diaz - 2021
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SLEEP_TIME  2

int main() {
    pid_t pid;

    pid = fork();

    if(pid < 0) {
        fprintf(stderr, "Fork faliled\n");
        return 1;
    }
    if(pid == 0) { // Child process
        printf("Child process: Value of variable \"pid\" = %d\n", pid);
        printf("Child process: Pause of %d seconds\n", SLEEP_TIME);
        sleep(SLEEP_TIME);
        printf("Child process: PID of child = %d\n", getpid());
    }
    else { // Parent process
        // Parent will wait for child to complete
        printf("Parent process: Value of variable \"pid\" = %d\n", pid);
        wait(NULL);
        printf("Parent process: Child completed\n");
        printf("Parent process: PID of parent = %d\n", getpid());
        printf("Parent process: PID of grandparent = %d\n", getppid());
    }

    return 0;
}

