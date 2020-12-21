#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n;
	int fd[2];
	char buf[201];
	char *data = "Hello World\n";
	pipe(fd);
	write(fd[1],data,strlen(data));
	if((n = read(fd[0],buf,200))>=0)
	{
		buf[n] = 0;
		printf("Read %d bytes from the pipe : %s\n",n,buf );
	}
	else{
		perror("read");
		exit(1);
	}
}