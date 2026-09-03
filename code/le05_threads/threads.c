/*
 Programa: Uso de threads

 Este programa ilustra como criar duas threads com a API pthread
 O programa recebe como entrada dois numeros inteiros
 Cada thread imprime um dos numeros em uma mensagem separada

 # Compilar
 gcc -o <nome-programa>.out <nome-programa>.c -lpthread

 @adapted_from: Figure 4.11
 Operating System Concepts - Tenth Edition
 Silberschatz, Galvin, and Gagne

 @author: Aldo Diaz, PhD, EE
                   Instituto de Informatica - INF
                   Universidade Federal de Goias - UFG
                   2021
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
// #include <fcntl.h>
// #include <semaphore.h>

#define NUM_THREADS  2

/* Declaracao de funcoes thread */
void *T0(void *param);
void *T1(void *param);

int main(int argc, char *argv[]) {
    pthread_t workers[NUM_THREADS]; // TID - Identificador da thread
    pthread_attr_t attr; // Thread PCB - Conjunto de atributos da thread

    // Validar argumentos de entrada
    if(argc != 3) {
        fprintf(stderr,"Sintaxe: <programa.out> <valor_inteiro> <valor_inteiro>\n");
        exit(-1);
    }
    if(atoi(argv[1]) < 0) {
        fprintf(stderr,"Argumento %d deve ser nao-negativo\n",atoi(argv[1]));
        exit(-1);
    }
    if(atoi(argv[2]) < 0) {
        fprintf(stderr,"Argumento %d deve ser nao-negativo\n",atoi(argv[2]));
	return -1;
    }

    // Definir threads com atributos padrao
    pthread_attr_init(&attr);

    // Criar threads
    pthread_create(&workers[1], &attr, T1, argv[2]);
    pthread_create(&workers[0], &attr, T0, argv[1]);

    // Aguardar threads finalizar
    for(int k=NUM_THREADS-1; k>=0; k--)
        pthread_join(workers[k], NULL);

    return 0;
}

// Definicao de funcoes thread
void *T0(void *param) {
    int upper = atoi(param);

    fprintf(stdout, "Sou T0: %d\n", upper);

    pthread_exit(0);
}

void *T1(void *param) {
    int upper = atoi(param);

    fprintf(stdout, "Sou T1: %d\n", upper);

    pthread_exit(0);
}

