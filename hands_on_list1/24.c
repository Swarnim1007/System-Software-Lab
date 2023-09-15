/*
============================================================================
Name : 24.c
Author : Swarnim Kukreti
Description :Write a program to create an orphan process. 
Date: 9th Sep, 2023.
============================================================================
*/
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{	
	int pid = fork();

	if (pid > 0)
		printf("in parent process\n");

	else if (pid == 0)
	{
		sleep(30);
		printf("in child process\n");
	}

	return 0;
}
i
