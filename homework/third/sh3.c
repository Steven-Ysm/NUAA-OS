#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

int file_open(char *path, int flag)
{
	mode_t mode = 0777;
	return open(path, flag, mode);
}

void mysys(char *command)
{
	char* vector[100];
  	char buffer[100];
  	strcpy(buffer, command);

	int fd_src = 0, fd_dst = 1;

  	char* word = strtok(buffer, " ");
  	int i = 0;
  	while (word != NULL) {
		if (word[0] == '>' || word[0] == '<') {
			if (word[0] == '>') {
				if (word[1] == '>')
					fd_dst = file_open(word + 2, O_WRONLY | O_CREAT | O_APPEND);
				else fd_dst = file_open(word + 1, O_WRONLY | O_CREAT | O_TRUNC);
			}
			else fd_src = file_open(word + 1, O_RDONLY);
		}
		else {
    			vector[i] = word;
    			i++;
		}
    		word = strtok(NULL, " ");
  	}
  	vector[i] = NULL;


  	if (strcmp(vector[0], "exit") == 0) {
    		exit(0);
  	}
  	else if (strcmp(vector[0], "cd") == 0) {
    		chdir(vector[1]);
    		return;
  	}
  	else if (strcmp(vector[0], "pwd") == 0) {
    		char work_dir[100];
    		getcwd(work_dir, sizeof(work_dir));
   		printf("%s\n", work_dir);
    		return;
  	}
  
	
	pid_t pid;
  	pid = fork();
  	if (pid == 0) {
			
		dup2(fd_src, 0);
		dup2(fd_dst, 1);

    		int error = execvp(vector[0], vector);
    		if (error < 0) {
      			perror("execvp");
      			exit(EXIT_FAILURE);
    		}
    		exit(EXIT_SUCCESS);
  	}

  	int status;
  	wait(&status);
}

int main(int argc, char* argv[])
{
	char command[100];
	while (1) {
		write(1, "> ", 2);
    		int c;
    		c = read(0, command, sizeof(command));
    		command[c - 1] = '\0';    //remove '\n'
   	 	mysys(command);
  	}
  	return 0;
}


