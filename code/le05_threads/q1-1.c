/*
  q1-1.c – serial

 1. Compilar:
 gcc -o q1-1.out q1-1.c -lm

 2. Executar:
 time ./q1-1.out
*/

#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#define CALLS 10

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
    for(int k=0; k<CALLS; k++) {
        if(k % 2)
            CPU_bound(k);
        else
            IO_bound(k);
    }
    
    printf("\n*** Tarefas concluidas ***\n");
    
    return 0;
}

