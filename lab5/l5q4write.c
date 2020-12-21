#include <stdio.h>
#include <stdlib.h>
struct threeNum
{
	int n1, n2, n3;
};
int main()
{
	int n = 1;
	struct threeNum num;
	FILE *fptr;
	if ((fptr = fopen("rbi.bin","wb")) == NULL){
		printf("Error! opening file");
		exit(1);
	}

	num.n1 = n;
	num.n2 = 5*n;
	num.n3 = 5*n + 1;
	fwrite(&num, sizeof(struct threeNum), 1, fptr);

	fclose(fptr);
	return 0;
}

