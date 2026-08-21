/*
  Example: Use of fork
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	pid_t pid;

	printf("Parent process. PID of grandparent = %d\n", getppid());
	printf("Child process. PID of parent = %d\n", getpid());

	if ((pid = fork()) != 0)
		printf("Parent process. PID of child = %d\n", pid);
	else {
		sleep(1);
		printf("Child process. PID = %d\n", getpid());
	}

	return 0;
}

