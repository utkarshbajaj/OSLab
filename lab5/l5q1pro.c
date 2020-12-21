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
	int pipe_fd, res, open_mode = O_WRONLY, bytes_sent = 0;
	char buffer[4];
	printf("Enter the Number\n");
	scanf("%s", buffer);
	if(access(FILE_NAME, F_OK) == -1) {
		res = mkfifo(FILE_NAME, 0777);
		if(res != 0) {
			printf("Cannot create fifo\n");
			exit(1);
		}
	}
	printf("Process %d opening fifo\n", getpid());
	pipe_fd = open(FILE_NAME, open_mode);
	printf("Process %d: Result %d\n", getpid(), pipe_fd);
	if(pipe_fd != -1) {
		res = write(pipe_fd, buffer, 4);
		if(res == -1) {
			printf("Error writing on pipe\n");
			exit(1);
		}
		close(pipe_fd);
	}
	else {
		printf("Error opening the pipe\n");
		exit(1);
	}
	printf("Finished\n");
}