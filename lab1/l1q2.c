#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	int sfd;
	for(int i = 1; i < argc; i++){
		sfd = open(argv[i], O_RDONLY);
		int lncnt = 0;
		if(sfd == -1){
			printf("Error opening file\n");
			exit(1);
		}
		char line[10005];
		char ch;
		int j = 0;
		while(read(sfd, &ch, sizeof(char)) > 0){
			if(ch == '\n'){
				line[j++] = '\0';
				printf("%s\n", line);
				++lncnt;
				if(lncnt % 20 == 0){
					char c;
					printf("Press a character to continue\n");
					c = getchar();
				}
				j = 0;
			} else {
				line[j++] = ch;
			}
		}
		close(sfd);
	}
	return 0;
}