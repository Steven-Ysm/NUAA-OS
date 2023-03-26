#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	for(int i=1; i < argc; i++){//agrv[0]为echo
		write(1, argv[i], strlen(argv[i]));
		write(1, " ", 1);
	}

	printf("\n");

	return 0;
}
