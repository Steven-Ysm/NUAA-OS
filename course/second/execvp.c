#include <stdio.h>
#include <unistd.h> 

int main()
{
    puts("before exec"); 
    char *argv[] = {"echo", "a", "b", "c", NULL};
    int error = execvp("echo", argv); 
    if (error < 0)
        perror("execv");
    puts("after exec");
    return 0;
}
