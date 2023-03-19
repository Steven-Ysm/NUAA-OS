#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc,char *argv[]){
	
	if (argc != 3){//参数量不等于3，不符合cp的要求
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

        read(file,buf,filesize);//读出该文件内容
	close(file);//关闭该文件，释放相应资源
		
	file = open(argv[2],O_WRONLY|O_CREAT);//只写模式或创建文件模式打开文件
        if(file < 0){
                printf("You open a wrong file.Please try again!\n");
                exit(0);
        }
	
	write(file,buf,filesize);//写入对应文件

        close(file);
	free(buf);//释放内存
        return 0;
}
