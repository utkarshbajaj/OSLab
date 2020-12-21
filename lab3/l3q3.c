#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){
	int status;
	pid_t pid;
	pid = fork();
	if(pid < 0){
		printf("Error\n");
		exit(1);
	} else if(!pid){
		printf("This is the child process\n");
		printf("Parent id: %d\n", getppid());
		printf("Current id: %d \n", getpid());
		exit(0);
	} else {
		wait(&status);
		printf("This is the parent process\n");
		printf("Parent id: %d\n", getppid());
		printf("Current id: %d\n", getpid());
		printf("Child id %d\n", pid);
	}
}