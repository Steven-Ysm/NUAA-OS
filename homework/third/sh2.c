#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_ARGC 256

void mysys(char *command)
{

    char *string = (char *)malloc( sizeof(command) );//创建一个动态字符数组
    strcpy(string, command);//复制输入的命令

    char *command_cut[MAX_ARGC];//创建一个存储分割后的命令的数组

    for(int i = 0; i < MAX_ARGC; i++)
        command_cut[i] = NULL;

    char *word;
    int count = 0;//记录存储命令的位置
	
    int fd_src = 0;//初始化fd的输入为0
    int fd_dst = 1;//初始化fd的输出为1

    word = strtok(string, " ");
    while (word != NULL) {
        if (word[0] == '>' || word[0] == '<') {//重定向输入，输出，追加
		if (word[0] == '>') { //重定向追加，输入
			if (word[1] == '>') //找到将标准输出重定向为追加的文件
				fd_dst = open(word + 2, O_CREAT | O_WRONLY | O_APPEND, 0666);
			else //找到需要将标准输出重定向的文件
				fd_dst = open(word + 1, O_CREAT | O_WRONLY, 0666);
		}
		else //找到需要将标准输入重定向的目标文件
		   	fd_src = open(word + 1, O_RDONLY, 0666);
	}
	else{//其余命令，直接存储
		command_cut[count] = word;
		count++;
	}

	word = strtok(NULL, " ");//继续分割
    }//分割完成
    
    if (strcmp(command_cut[0], "cd") == 0 ) {//cd命令
    	if(command_cut[1])
		chdir(command_cut[1]);//更改目录
	return;
    }
    else if (strcmp(command_cut[0], "exit") == 0) //exit命令
    	exit(0);
    else if (strcmp(command_cut[0], "pwd") == 0) { //pwd命令
    	char work_dir[100];
    	getcwd(work_dir, sizeof(work_dir));
   	printf("%s\n", work_dir);
  	return;
    } 
    else {
    	pid_t pid;
	pid = fork();
	if( pid == 0) {
		dup2(fd_src, 0); // 将标准输入重定向为文件
		dup2(fd_dst, 1); // 将标准输出重定向为文件
		
		execvp(command_cut[0], command_cut);
	}
    }

    wait(NULL);
}

int main()
{
    while(1){
	char line[100];
	int c;
	
	write(1, ">", sizeof(">"));
	c = read(0, line, sizeof(line)); 
	line[c - 1] = 0;
	
	mysys(line);
    }
}
