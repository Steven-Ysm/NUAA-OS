#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    int fd;

    fd = open("/etc/hosts", O_RDONLY); 
    printf("open(/etc/hosts) = %d\n", fd);
    close(fd);

    return 0;
}
