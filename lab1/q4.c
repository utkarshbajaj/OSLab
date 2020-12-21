#include <stdio.h>
int main(int argc, char const *argv[])
{
	FILE *fa, *fb;
	int ca;
	fa = fopen("q4in.txt", "r");
	if(fa == NULL){
		printf("Cannot open file");
		return 0;
	}
	fb = fopen("q4out.txt", "w");
	ca = getc(fa);
	while(ca != EOF){
		putc(ca, fb);
		ca = getc(fa);
	}
	fclose(fa);
	fclose(fb);
	return 0;
}