#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#define max_size 100
int main()
{

    int fd1,fd2;
    char buf[max_size];
    int check;
    fd1=open("srs.txt",O_RDWR,S_IRUSR);
    if(-1==fd1)
    {
        perror("Error opening the file");
        exit(EXIT_FAILURE);
    }

    check=read(fd1,&buf,max_size);
    if(-1==check)
    {
        perror("error Reading the file");
        exit(EXIT_FAILURE);
    }

    fd2=open("dst.txt",O_CREAT|O_WRONLY,S_IRUSR|S_IWUSR);
    if(-1==fd2)
    {
        perror("Error opening");
        exit(EXIT_FAILURE);
    }
     write(fd2,&buf,check);
     close(fd1);
     close(fd2);
     return 0;
    }




