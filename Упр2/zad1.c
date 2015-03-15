#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc, char* argv[]) {
 char buf[11];
 int fd1 = open("ff", O_RDONLY);
 int fd2 = open("ff", O_WRONLY);
 lseek(fd2, 6, 0);
 write(fd2, "xyzw", 4);
 lseek(fd2, 4, 0);
 write(fd2, "12", 2);
 read(fd1, buf, 10);
 printf("%s\n", buf);
 close(fd1);
 close(fd2);
 return 0;
}
