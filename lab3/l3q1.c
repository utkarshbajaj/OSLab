#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void main()
{
	pid_t pid;
	int status;
	char *message;
	int n;
	printf("Fork program starting\n");
	pid = fork();
	if(pid == -1){
		printf("Error\n");
		exit(0);
	} else if(!pid){
		printf("I am the child\n");
		exit(0);
	} else {
		wait(&status);
		printf("I am the parent\n");
		printf("Child returned now\n");
	}
	exit(0);
}