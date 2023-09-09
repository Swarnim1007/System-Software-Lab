/*
============================================================================
Name :16(b).c
Author : Swarnim Kukreti
Description : Write a program to perform mandatory locking. 
	a. Implement write lock
	b. Implement read lock
Date: 9th Sep, 2023.
============================================================================
*/
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>

int main(void) {
	struct flock lock;
	int fd;
	fd = open("db", O_RDWR);
	lock.l_type=F_WRLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=0;
	lock.l_len=0;
	lock.l_pid=getpid();
	printf("Before entering into critical section\n");

	if(fcntl(fd, F_SETLKW, &lock)==-1)
	{perror("error acquiring write lock");
		close(fd);
		return 1;
	}

	printf("Inside the critical section.....\n");
	printf("Enter to unlock...\n");
	getchar();
	printf("unlocked\n");
	lock.l_type=F_UNLCK;

	if(fcntl(fd, F_SETLK, &lock)==-1)
	{
		perror("Error releasing write lock");
		close(fd);
		return 1;
	}
	printf("finish\n");
}
