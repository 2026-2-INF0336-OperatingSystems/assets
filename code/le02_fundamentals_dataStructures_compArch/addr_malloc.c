/* 
  Verification of addresses with dynamic allocation
*/ 

#include <stdio.h>
#include <malloc.h>

int v1;

int main() {
    int v2;
    int *v3 = malloc (sizeof(int));
    int *v4 = malloc (1024*4096*sizeof(int));

    printf("Endereco de main() = %p \n", main);
    printf("Endereco de v1     = %p \n", &v1);
    printf("Endereco de v2     = %p \n", &v2);
    printf("Endereco de v3     = %p \n", &v3);
    printf("Conteudo de v3     = %p \n", v3);
    printf("Endereco de v4     = %p \n", &v4);
    printf("Conteudo de v4     = %p \n", v4);

    return 0;
}

