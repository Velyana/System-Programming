#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc, char* argv[]) {
 int fd1 = open(argv[1], O_RDONLY);
 int fd2 = open(argv[2], O_WRONLY | O_CREAT, 0644);
 char c, a;
 lseek(fd2, 0, SEEK_END);
 while(read(fd1, &c, 1) || read(1, &a, 1)) {
  if(!(c >= '0' && c <= '9')) {
   write(fd2, &c, 1); }
   read(1, &a, 1);
   if(!(a >= '0' && a <= '9')) {
   write(fd2, &a, 1);
    }
 }
}
