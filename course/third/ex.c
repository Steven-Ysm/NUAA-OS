#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

void dump(int fd)
{
	char buf[128];
	int count;

	count = read(fd, buf, sizeof(buf));
	buf[count] = 0;
	puts(buf);
}

int main()
{
	pid_t pid;
	int fd;

	fd = open("/etc/passwd", O_RDONLY);
	pid = fork();
	if (pid == 0)
		dump(fd);
	return 0;
}
