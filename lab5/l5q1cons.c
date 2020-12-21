#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
 
#define FILE_NAME "my_fifoa"

int main() {
	int pipe_fd, res, open_mode = O_RDONLY, bytes_sent = 0;
	char buffer[4];
	memset(buffer, '\0', sizeof(buffer));
	printf("Process %d opening fifo\n", getpid());
	pipe_fd = open(FILE_NAME, open_mode);
	printf("Process %d: Result %d\n", getpid(), pipe_fd);
	if(pipe_fd != -1)	{
		res = read(pipe_fd, buffer,4);
		printf("Recieved: %s\n", buffer);
	}
	else {
		printf("Error opening the pipe\n");
		exit(1);
	}
	printf("Finished\n");
}