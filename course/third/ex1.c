#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>  //使用open包含前三个
#include <unistd.h> //使用read、write
#include <stdio.h>

int main()
{
	int fd;
	fd = open("/etc/hosts", O_RDONLY);
	
	char buf[1024];
	int count;
	count = read(fd, buf, sizeof(buf));
	
	buf[count] = 0;
	puts(buf);

	close(fd);
	return 0;
}
