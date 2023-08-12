#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>

int main()
{
	const char *f1="fourth.txt";
	int frd=open(f1,O_RDWR);
	if(frd==-1)
	{
		perror("error in reading mode");
			return 1;
	}
	else
	{
		printf("file opened successfully in RM          ");
		
		close(frd);
	}

	int fwd=open(f1,O_RDWR | O_EXCL);
	if(fwd==-1)
	{		
	if(errno==EEXIST)
				{
					perror("File already exist(O_EXCL flag)");
					}

			else{
				error("Error opening file with O_EXCL flag");
			}
	}
		else
		{printf("File opened successfully  with O_EXCL flag           ");
			close(fwd);
		}
		return 0;
}


