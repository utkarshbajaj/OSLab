#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	char file[100];
	struct stat sb;
	int ret;
	printf("Enter the file name\n");
	scanf("%s", file);
	ret = stat(file, &sb);
	if(ret){
		perror("stat");
		exit(1);
	}
	printf("Inode number of file %s is %ld\n", file, sb.st_ino);
	return 0;
}