#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int fd=creat("example.txt",S_IRUSR | S_IWUSR);

	if(fd==-1)
	{perror("Error on creating file");
		return 1;
	}
	printf("file created successfully with discriptor value %d",fd);

	if(close(fd)==-1)
	{
		perror("Errorr on creating file");
		return 1;
	}
	return 0;
}
