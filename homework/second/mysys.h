#define MAX_ARGC 16
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


    
    //for(int i=0; i<count; i++)
    //	    printf(command1[i]);    
    pid = fork();//创建子进程
    if(pid == 0){
    	execvp(command1[0],command1);
    }	    

    wait(NULL);
}

