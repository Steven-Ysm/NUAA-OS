#include <stdio.h>
#include <stdlib.h>

int main(){
	puts("before exit");
	exit(100);
	puts("after exit");
	return 0;
}
