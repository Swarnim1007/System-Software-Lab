#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{
	struct flock lock;
	int fd;
	fd=open("db",O_RDWR);
	lock.l_type=F_WRLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=0;
	lock.l_len=0;
	lock.l_pid=getpid();
	printf("Before entering C.S.\n");
	fcntl(fd,F_SETLKW,&lock);
	printf("Inside critical sec   \n");
	printf("Enter to unlock    \n");
	getchar();
	printf("Unlocked  \n");
	lock.l_type=F_UNLCK;
	fcntl(fd,F_SETLK,&lock);
	printf("Finish  \n");
}
