#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	int pid;
	int fd[2];
	char buf[32];

	pipe(fd); 
    	pid = fork();
    	if (pid == 0) { 
        	// child
        	dup2(fd[1], 1); 
  	        close(fd[0]);
        	close(fd[1]);

        	write(1, "hello", 6); 
    	    	exit(0);
    	}
    	// parent
    	dup2(fd[0], 0); 
    	close(fd[0]);
    	close(fd[1]);

    	read(0, buf, sizeof(buf)); 
	printf("Receive:%s\n", buf); 
    	return 0;	
}
