/*
  Program: Use of signals v1.0

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

// Signal handling function
void confirm_exit(int sig) {
    // KeyboardInterrupt: User signal <CTRL+C>
    if(sig == SIGINT) {
        printf("\nUser signal received: SIGINT (Signal Interrupt)\n");
        printf("Are you sure you want to exit [y/n]? ");
        if(getchar() == 'y')
            exit(0);
    }
}

int main() {
    // Associate the signal handler function with a specific signal
    if(signal(SIGINT, confirm_exit) == SIG_ERR)
        fprintf(stderr, "Unable to pick up signal");

    printf("Welcome to signal v1.0\n");

    // Perform a long wait
    while(1)
        sleep(1);

    return 0;
}

