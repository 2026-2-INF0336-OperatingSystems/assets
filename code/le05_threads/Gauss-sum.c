#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 4

// Funcao para calcular o somatorio de Gauss, em uma parte especifica do intervalo
void* calcularSomatorio(void* arg) {
    int* params = (int*)arg;
    int start = params[0];
    int end = params[1];

    double* result = malloc(sizeof(double));
    *result = 0.0;

    for(int k = start; k<=end; ++k) {
        *result += k;
    }

    pthread_exit(result);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Uso: %s <N>\n", argv[0]);
        printf("Onde <N> eh o valor limite do somatorio de Gauss.\n");
        return 1;
    }

    int N = atoi(argv[1]);

    if (N <= 0) {
        printf("Por favor, insira um valor positivo para N.\n");
        return 1;
    }

    double resultado_total = 0.0;
    pthread_t threads[MAX_THREADS];
    int params[MAX_THREADS][2];

    // Dividir o intervalo [1, N] em partes iguais para as threads
    int intervalo = N / MAX_THREADS;
    int inicio = 1;

    // Criar e executar threads
    for (int k = 0; k < MAX_THREADS; ++k) {
        params[k][0] = inicio;
        params[k][1] = (k == MAX_THREADS - 1) ? N : inicio + intervalo - 1;

        pthread_create(&threads[k], NULL, calcularSomatorio, (void*)params[k]);

        // Atualizar o inicio para a proxima thread
        inicio += intervalo;
    }

    // Aguardar o termino das threads e somar todos os resultados parciais
    for (int k = 0; k < MAX_THREADS; ++k) {
        double* threadResult;
        pthread_join(threads[k], (void**)&threadResult);
        resultado_total += *threadResult;
        free(threadResult);
    }

    // Imprimir o resultado total
    printf("O somatorio de Gauss da expressao n de 1 ate %d eh: %.2f\n", N, resultado_total);

    return 0;
}

