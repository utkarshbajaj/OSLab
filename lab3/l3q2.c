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
		printf("Loading the binary executable in the child process\n");
		printf("Executing child process\n");
		execl("./p1", "p1", NULL);
	} else {
		wait(NULL);
		printf("Parent Process\n");
		exit(0);
	}
	exit(0);
}