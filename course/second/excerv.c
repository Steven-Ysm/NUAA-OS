#include <stdio.h>
#include <unistd.h>

int main()
{
	puts("before exec");
	char *argv[] = {"echo", "a", "b", "c", NULL};
	int error  = execv("/usr/bin/echo", argv);
	if(error < 0)
		perror("exec");
	puts("after exec");
	return 0;
}
