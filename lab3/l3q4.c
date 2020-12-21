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
		printf("Inside child\n");
		exit(0);
	} else {
		printf("Inside parent\n");
		sleep(1);
		execl("/bin/ps", "ps", NULL);
	}
	exit(0);
}