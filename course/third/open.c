#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int fd;

	close(2);	
	fd = open("/etc/hosts", O_RDONLY);	
	if(fd < 0){
	       perror("Open");
       		exit(0);
	}
	
	printf("open(/etc/hosts) = %d\n", fd);

	return 0;	
}
