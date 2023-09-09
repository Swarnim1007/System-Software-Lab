/*
============================================================================
Name : 23.c
Author : Swarnim Kukreti
Description :Write a program to create a Zombie state of the running program 
Date: 9th Sep, 2023.
============================================================================
*/
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	// Fork returns process id
	// in parent process
	pid_t child_pid = fork();

	// Parent process
	if (child_pid > 0)
		sleep(50);

	// Child process
	else{
	
		exit(0);

	}
	return 0;
}

