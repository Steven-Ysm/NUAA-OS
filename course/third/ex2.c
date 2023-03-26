#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd;
	fd = open("log2.txt", O_CREAT|O_RDWR, 0666);
	dup2(fd, 1);
	close(fd);
	write(1, "hello\n", 6);
	return 0;
}
