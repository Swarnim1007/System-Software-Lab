#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
int v=symlink("notes.txt","soft1.txt");
if(v<0)
{
	perror("Failed");return 1;}

	int f=link("notes.txt","hard1.txt");
	if(f<0)
{perror("failed");return 1;}
int e=mknod("comm1",S_IFIFO,0);
if(e<0)
	perror("Failed");
	return 0;
	}
