#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();

    if(pid < 0) {
        fprintf(stderr, "Fork falhou\n");
        return 1;
    }

    if(pid == 0) { // SO criou o processo filho
        // Bloco do programa filho
        // execlp("/usr/bin/ls", "ls", NULL);
        printf("PID do processo filho: %d\n", getpid());
        printf("PID do processo pai: %d\n",   getppid());
    }
    else {
        // Bloco do programa pai
        wait(NULL);
        printf("Processo filho terminou\n");
    }

    return 0;
}