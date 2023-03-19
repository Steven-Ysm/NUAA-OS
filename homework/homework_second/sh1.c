#include <stdio.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

#define MAX_ARGC 256

void mysys(char *command)
{
    pid_t pid;//子进程

    if(command == NULL){//命令为空
        printf("Please Check Your Command!Try again!");
        exit(0);
    }

    char *string = (char *)malloc(sizeof(command));//创建一个动态字符数组
    strcpy(string,command);//复制输入的命令

    char *command1[MAX_ARGC];//创建一个存储分割后的命令的数组

    for(int i = 0; i < MAX_ARGC; i++)
        command1[i] = NULL;

    char *word;
    int count = 0;//记录存储命令的位置

    word = strtok(string, " ");
    while(word != NULL){
        command1[count] = word;
        count++;
        word = strtok(NULL, " ");
    }//分割完成
    
    if(strcmp(command1[0],"cd") == 0 ){
    	if(command1[1])
		chdir(command1[1]);//更改目录
	return;
    }
    else if(strcmp(command1[0],"exit") == 0){
    	exit(0);
    }
	
    pid = fork();//创建子进程，执行其他命令，pwd，echo，ls等
    if(pid == 0){
        execvp(command1[0],command1);
    }

    wait(NULL);
}
int main(){
	while(1){
		char line[100];
		int c;
		write(1,">",sizeof(">"));
    		c = read(0, line, sizeof(line));  // 0 是标准输入
    		//write(1, line, c);                // 1 是标准输出
		line[c-1]=0;
		mysys(line);
	}
}
