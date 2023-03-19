#include <stdio.h>
#include <unistd.h> 

int main()
{
    puts("before exec");
    int error = execlp("echo", "echo", "a", "b", "c", NULL); 
    if (error < 0)
        perror("execl");
    puts("after exec");
    return 0;
}
