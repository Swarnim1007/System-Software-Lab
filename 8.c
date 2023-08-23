#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<unistd.h>
int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("Invallid argum");
		return 0;
	}

 	 char buf;
         int  fd_read=open(argv[1],O_RDONLY);
	  while(1)
	  {		 int read_file= read(fd_read,&buf,1);
		  	if(read_file==0)
				break;
	  
		  printf("%c",buf);


	  }
	  
	  int fd_read_close=close(fd_read);
	 

	  if(fd_read_close==-1)
		  printf("Totally useless");
	return 0;
        }


