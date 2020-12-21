#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

void main(int argc, char const *argv[])
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
	printf("\nID of device: %ld",sb.st_dev);
	printf("\nInode no.: %ld",sb.st_ino);
	printf("\nPermissions: %o",sb.st_mode);
	printf("\nNo. of hard links: %ld",sb.st_nlink);
	printf("\nUser ID of owner: %d",sb.st_uid);
	printf("\ngroup ID of owner: %d",sb.st_gid);
	printf("\ndevice ID: %ld",sb.st_rdev);
	printf("\nTotal size: %ld",sb.st_size);
	printf("\nBlocksize: %ld",sb.st_blksize);
	printf("\nNo. of blocks: %ld",sb.st_blocks);
	printf("\nLast access time: %s",ctime(&sb.st_atime));
	printf("\nLast modification time: %s",ctime(&sb.st_mtime));
	printf("\nStatus change time: %s",ctime(&sb.st_ctime));
	exit(0);
}