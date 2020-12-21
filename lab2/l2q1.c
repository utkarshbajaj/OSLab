#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

void printdir(char *dir, int depth){
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;
	if((dp = opendir(dir)) == NULL){
		fprintf(stderr, "Cannot open directory: %s\n", dir);
		return;
	}
	chdir(dir);
	while((entry = readdir(dp)) != NULL){
		lstat(entry -> d_name, &statbuf);
		if(S_ISDIR(statbuf.st_mode)){
			if(strcmp(".", entry -> d_name) == 0 || strcmp("..", entry -> d_name) == 0)
				continue;
		} 
		printf((S_ISDIR(statbuf.st_mode))  ? "d" : "-");
		printf(" ");
		printf((statbuf.st_mode & S_IRUSR) ? "r" : "-");
		printf((statbuf.st_mode & S_IWUSR) ? "w" : "-");
		printf((statbuf.st_mode & S_IXUSR) ? "x" : "-");
		printf((statbuf.st_mode & S_IRGRP) ? "r" : "-");
		printf((statbuf.st_mode & S_IWGRP) ? "w" : "-");
		printf((statbuf.st_mode & S_IXGRP) ? "x" : "-");
		printf((statbuf.st_mode & S_IROTH) ? "r" : "-");
		printf((statbuf.st_mode & S_IWOTH) ? "w" : "-");
		printf((statbuf.st_mode & S_IXOTH) ? "x" : "-");
		printf("\t %s \t", entry->d_name);
		printf("\n");
	}
	chdir("..");
	closedir(dp);
}

int main(int argc, char const *argv[])
{
	char ch[] = "/home/Student/Desktop/b253_os/lab2";
	char *p = ch;
	printdir(p, 0);
	return 0;
}