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
