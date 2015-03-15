#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc, char* argv[]) {
 char buf[100];
 int nbytes;
 int fd1 = open(argv[1], O_RDONLY);
 int fd2 = open(argv[2], O_WRONLY);
 while(nbytes = read(fd1, buf, 100)) {
  write(fd2, buf, nbytes);
 }
 close(fd1);
 close(fd2);
return 0;
}
