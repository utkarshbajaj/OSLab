#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

void main(int argc, char const *argv[]){
	struct stat sb;
	int ret;
	puts("Before linking");
	system("ls -il test.*");
	char path[100];
	printf("Enter the pathname\n");
	scanf("%s", path);
	ret = link("test.txt", path);
	if(ret){
		printf("Error\n");
		exit(1);
	} else {
		printf("After Link\n");
		system("ls -il test.*");
		system("ls -il ./new/test2.txt");
	}
	ret = unlink("test.txt");
	if(ret){
		perror("Unlink error");
		exit(1);
	} else {
		printf("After unlink\n");
		system("ls -il test.*");
	}
}