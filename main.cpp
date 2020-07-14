#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <arpa/inet.h> 
#include "sum.h"

int main(int argc, char *argv[]) {


	FILE *fd, *fd1, *fd2, *fd3;
	int n, n1;
	char buf[20];
	uint32_t test1 = 1000;
	uint32_t test2 = 500;
	uint32_t test3 = 0;
	uint32_t test4 = 0;
	uint32_t test5 = 0;
	uint32_t test6 = 0;
	int a=1;
	int b=1;	
	fd=fopen(argv[1],"rb");
	fd1=fopen(argv[2], "rb");
	while((n=fgetc(fd)) != EOF)
	{
		if(a==3)
		{n=n*256;}
		test4 = test4|n;
		a++;
	}
	
	while((n1=fgetc(fd1)) != EOF)
	{
		if(b==3)
		{n1=n1*256;}
		test5 = test5|n1;
		b++;
	}
	test6 = sum(test4, test5);	


	printf("%u(0x%04x) + %u(0x%04x) = %u(0x%04x)\n", test4, test4, test5, test5, test6, test6);
	fclose(fd1);
	fclose(fd);
	return 0;

}
