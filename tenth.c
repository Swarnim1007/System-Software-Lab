#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
   int fd = open("sample.txt",O_RDWR|O_CREAT | O_TRUNC, 0666);
   if(fd== -1)
   {
           perror("error in opening file");
           return 1;

    }
   const char d1[]="0123456789";
   ssize_t byt= write(fd,d1,sizeof(d1)-1);

   if(byt ==-1)
   {
           perror("error writting data");
           close(fd);
           return 1;
   }

   off_t offset = lseek(fd, 10, SEEK_CUR);
   if(offset == -1)
   {
           perror("error seeking");
           close(fd);
           return 1;
   }

   //write more 10B
   const char d2[]="SwarnimKukreti";
   byt = write(fd, d2, sizeof(d2) -1);
   if(byt==-1)
   {
           perror("error writing");
           close(fd);
           return 1;
   }
   close(fd);
   printf("lseek returned offset: %ld\n", offset);
   return 0;
}
