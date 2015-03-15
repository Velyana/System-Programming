#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc, char* argv[]) {
 char buf[100];
 int nbytes;
 int fd = open(argv[1], O_CREAT | O_WRONLY, 0644);
 while(nbytes = read(0, buf, 100)) {
  write(fd, buf, nbytes);
  write(1, buf, nbytes);
 }
 close(fd);
 return 0;
}
