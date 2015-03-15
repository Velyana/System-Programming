#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc, char* argv[]) {
 int fd, i, status;
 if(fork()) {
  wait(&status);
  for(i = 0; i <=3; i++) {
   write(1, "cal\n", 4);
   execlp("cal", "cal", 0);
   write(1, "hello1\n", 7); }
  } else {
  close(1);
  fd = open(argv[1], O_RDWR);
  write(1, "hello2\n", 7);
 }
 write(1, "hello3\n", 7);
}
