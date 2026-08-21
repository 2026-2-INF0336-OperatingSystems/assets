/*
  Corrupting the execution queue
*/

#include <stdio.h>

void f() {
    int *v[2]; 
    int i;

    for(i = 0; i < 16; i++)
        v[i] = &i;
}

int main() {
    f();

    return 0;
}

