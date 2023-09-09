/*
============================================================================
Name : 21.c
Author : Swarnim Kukreti
Description :Write a program, call fork and print the parent and child process id. 
Date: 9th Sep, 2023.
============================================================================
*/
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	if(fork())
	{
		printf("Parent pid  %d",getpid());
	}
	else
	{
		printf("Child pid  %d",getpid());
	}
	return 0;
}
