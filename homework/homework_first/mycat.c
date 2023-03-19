#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc,char *argv[]){

	if (argc < 2){//参数量太少，不符合要求
		printf("You enter wrong parameter.Please try again!\n");
		exit(0);
	}

	int file;

	file = open(argv[1],O_RDONLY);//只读模式打开文件
	if(file < 0){
		printf("You open a wrong file.Please try again!\n");
		exit(0);
	}

	struct stat st;

	stat(argv[1], &st);//文件大小
	
	int filesize;
	filesize = st.st_size;
	
	char *buf;//内存缓冲区起始位置
	buf = (char *)malloc((1+filesize)*sizeof(char));

	if(buf == 0){
		printf("You create wrong memory.Please try again!\n");
		exit(0);
	}

	read(file,buf,filesize);
	write(1,buf,filesize);//直接输出
	
	close(file);
	free(buf);//释放内存
	return 0;
}
