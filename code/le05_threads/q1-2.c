/*
 prog2.c – multiplos processos

 1. Compilar:
 gcc -o q1-2.out q1-2.c -lm

 2. Executar
 time ./q1-2.out
*/

#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#define NPROCESS 10

void CPU_bound(int id) {
    double result=0.0;
    
    // Simula operacoes de alto consumo de CPU
    for(int k=0; k<10000; k++)
        result = result + sin(k) * tan(k) * sqrt(result);
        
    printf("%d: CPU intensiva terminada\n", id);
}

void IO_bound(int id) {
    // Simula operacoes de I/O, as quais levam a bloqueio
    sleep(1);

    printf("%d: I/O intensiva terminada\n", id);
}

int main() {
    int status;
    pid_t children[NPROCESS];
    
    for(int k=0; k<NPROCESS; k++) {
        if(k % 2) {
            children[k] = fork();
            
            if(children[k] == 0) {
                CPU_bound(k);
                exit(0);
            }
        }
        else {
            children[k] = fork();
            
            if(children[k] == 0) {
                IO_bound(k);
                exit(0);
            }
        }
    }
    
    for(int k=0; k<NPROCESS; k++)
        waitpid(children[k], &status, 0);
        
    printf("\n*** Tarefas concluidas ***\n");
    
    return 0;
}

