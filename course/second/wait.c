#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void child(){
	puts("Child process");
	exit(123);
}

int main(){
	int pid;
	pid = fork();
	if(pid == 0)
		child();
	wait(NULL);//等待子进程结束
	puts("Parent process");
	return 0;
}
