#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main() 
{
	int a = 40, errno;
	char s[] = "utkarsh";
	float b = 9.3;
	char c = 'c';
	printf("Integer D %d\n", a);
	printf("Integer I %i\n", a);
	printf("Octal I%o\n", a);
	printf("Hexadecimal %x\n", a);
	printf("Char %c\n", c);
	printf("Float %f\n", b);
	printf("Double Precsion %e\n", b);
	printf("Double standard%g\n", b);
	errno = open("hello.txt", O_RDONLY);
	printf("\nError NO. : %m\n");
}