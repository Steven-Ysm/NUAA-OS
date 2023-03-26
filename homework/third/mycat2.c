#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void copy(int src_fd, int dst_fd)
{
	char buf[512];
	int count;
	while((count = read(src_fd, buf, 512)))
		write(dst_fd, buf, count);
}
int main(int argc, char *argv[])
{
	int fd;

	if (argc == 1)
		fd = 0;
	else{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0){
			perror("open");
			exit(0);
		}
	}

	copy(fd, 1);
	
	close(fd);

	return 0;
}
