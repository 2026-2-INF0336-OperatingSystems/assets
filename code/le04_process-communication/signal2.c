/*
  Program: Use of signals v2.0

  # 1. Compile:
      gcc -o <my-program>.out <my-program>.c

  # 2. Run:
  ./<my-program>.out

  # 3. SIGINT signal corresponds to <CTRL+C>

  @author: Aldo Diaz, PhD, EE
           Instituto de Informatica - INF
           Universidade Federal de Goias - UFG
  Copyright Aldo Diaz, 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static int flag = 0;

// Signal handling function
void confirm_exit(int sig) {
    // Set flag to ON
    flag = 1;
}

int main() {
    void *sig;
    char key;

    // Associate the signal handler function with a specific signal
    sig = signal(SIGINT, confirma_saida);

    if(sig == SIG_ERR)
        fprintf(stderr, "Unable to pick up signal");

    // Main program
    printf("Welcome to signal 2.0 RELOADED!\n");
    while(1) {
        if(flag == 1) { // Flag ON
            // Set flag to OFF
            flag = 0;

            // Read the keyboard
            printf("\nAre you sure you want to exit [y/n]? ");
            key = getchar();
            if(key == 'y')
                exit(0);
        }
        else // Flag OFF
            sleep(1);
    }

    return 0;
}

