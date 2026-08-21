/*
  Program: Sibbling processes

  @author: Aldo Diaz, PhD, EE
           Instituto de Informatica - INF
           Universidade Federal de Goias - UFG
  Aldo Diaz, 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    for(int i=0; i<5; i++) { // loop will run 'n' times (n=5)
        if(fork() == 0) {
            printf("[child] pid %d from [parent] pid %d\n",getpid(),getppid());
            exit(0);
        }
    }
    
    for(int i=0; i<5; i++) // loop will run 'n' times (n=5)
    wait(NULL);
}

