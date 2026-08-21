/*
  Example: Process hierarchy
                   A
                 /   \
                B     C
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    if(fork())
        if(fork())
	    printf("Process B\n");
	else
	    printf("Process C\n");
    else
        printf("Process A\n");

    return 0;
}

