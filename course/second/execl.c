#include <stdio.h>
#include <unistd.h>

int main()
{
	puts("befor exec");
	int error = execl("/usr/bin/echo", "echo", "a", "b", "c", NULL);
	if(error < 0)
		perror("excel");
	puts("after exec");
	return 0;
}
