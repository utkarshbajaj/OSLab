#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[]){
	int sfd;
	if(argc != 3){
		printf("Insuffient Number of args\n");
		exit(1);
	}
	sfd = open(argv[1], O_RDONLY);
	if(sfd == -1){
		printf("Couldn't open file!");
		exit(1);
	}
	char line[1024];
	char ch;
	int i = 0;
	int line_no = 0;
	while(read(sfd, &ch, sizeof(char)) > 0){
		if(ch != '\n' || ch == EOF){
			line[i++] = ch;
		} else {
			line[i] = '\0';
			if(strstr(line, argv[2]) != NULL){
				printf("Line %d:\t%s\n", line_no, line);
			}
			i = 0;
			line_no++;
		}
	}
	close(sfd);
	return 0;
}