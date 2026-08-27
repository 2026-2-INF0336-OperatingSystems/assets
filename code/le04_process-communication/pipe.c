/*
  Program: Use of pipes in UNIX

  @adapted_from: Figures 3.21 & 3.22
  Operating System Concepts - Tenth Edition
  Silberschatz, Galvin, and Gagne

  @author: Aldo Diaz, PhD, EE
           Instituto de Informatica - INF
           Universidade Federal de Goias - UFG
  Copyright Aldo Diaz, 2021
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define BUFFER_SIZE  43
#define READ_END      0
#define WRITE_END     1

int main(void) {
    pid_t pid;
    int fd[2];
    char write_msg[BUFFER_SIZE] = "Testing parent-child communication";
    char read_msg[BUFFER_SIZE];

    // Create pipe
    if(pipe(fd) == -1) {
        fprintf(stderr, "Pipe failed");
        return 1;
    }

    // Create child process
    pid = fork();

    if(pid < 0) {
        fprintf(stderr, "Fork failed");
        return 1;
    }
    if(pid > 0) {  // Parent process
        // Close the (unused) read end of the pipe
        close(fd[READ_END]);

        // Write to the pipe
        printf("Parent: Write message to pipe\n");
        write(fd[WRITE_END], write_msg, strlen(write_msg)+1);

        // Close the write end of the pipe
        close(fd[WRITE_END]);
    }
    else { // Child process
        // Close the (unused) write end of the pipe
        close(fd[WRITE_END]);

        // Read pipe
        read(fd[READ_END], read_msg, BUFFER_SIZE);
        printf("Child read: %s\n", read_msg);

        // Close the read end of the pipe
        close(fd[READ_END]);
    }

    return 0;
}

