#include<unistd.h>
#include<errno.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<stdio.h>
int main(){
	int fd=open("sample.txt",O_RDONLY);
	int flags,accessMode;
	flags=fcntl(fd,F_GETFL);
	if(flags==-1)
		exit(1);
	printf("opening mode %d \n",flags);
}
