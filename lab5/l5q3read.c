#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<limits.h>
#include<sys/types.h>
#include<sys/stat.h>
 
#define FILE_NAME "/tmp/my_fifo1"

int main()
{
	int pipe_fd1,pipe_fd2;
	int res;
	char buffer1[100],buffer2[100];
	while(1)
	{
		

		pipe_fd1 = open(FILE_NAME,O_RDONLY);
		res = read(pipe_fd1,buffer1,sizeof(buffer1));
		if(strcmp(buffer1,"exit")==0)
			break;
		if(res==-1)
		{
			printf("Error reading from pipe\n");
			exit(1);
		}

		printf("Recieved from file 1 : %s\n",buffer1);

		pipe_fd2 = open(FILE_NAME,O_WRONLY);
		printf("Enter string : \n");
		gets(buffer2);
		res = write(pipe_fd2,buffer2,strlen(buffer2)+1);
		if(strcmp(buffer2,"exit")==0)
			break;
		if(res==-1)
		{
			printf("Error writing on pipe\n");
			exit(1);
		}
	}


}
