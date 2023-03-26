#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    int fd;

    fd = open("/etc/passwd", O_RDONLY); 
    printf("open(/etc/passwd) = %d\n", fd);
    close(fd);

    return 0;
}

