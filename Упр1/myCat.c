#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc, char* argv[]) {
 char buf[100];
 int nbytes;
 int fd = open(argv[1], O_CREAT | O_RDONLY, 0644);
 while(nbytes = read(fd, buf, 100)) {
  write(1, buf, nbytes);
 }
 close(fd);
 return 0;
}
