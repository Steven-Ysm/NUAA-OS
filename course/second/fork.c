#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	
	pid = fork();
	
	//printf("pid = %d\n", pid);
	//if(pid == 0)
	//	printf("In child process\n");
	//else
	//	printf("In parent process\n");
	
	if(pid == 0)
		printf("In child:  child  PID = %d, parent PID = %d\n", getpid(), getppid());
	else
		printf("In parent: parent PID = %d, child  PID = %d\n", getpid(), pid);

	return 0;
}
