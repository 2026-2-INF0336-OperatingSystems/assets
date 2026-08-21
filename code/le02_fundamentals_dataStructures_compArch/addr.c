/* 
  Verification of addresses
*/ 

#include <stdio.h>

int v1;

void f(int v3) {
    int v4;

    printf("Address of v3     = %p \n", &v3);
    printf("Address of v4     = %p \n", &v4);
}

int main() {
    int v2;

    printf("Address of main() = %p \n", main);
    printf("Address of f()    = %p \n", f);

    printf("Address of v1     = %p \n", &v1);
    printf("Address of v2     = %p \n", &v2); 
    f(0);

    return 0;
}

