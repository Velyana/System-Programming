#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc, char* argv[]) {
 int fdin, fdout, fderr;
 if(fork()) {
  int stat;
  wait(&stat);
  printf("%d\n", stat);
 } else {
 close(0);
 fdin = open(argv[1], O_RDONLY);
 close(1);
 fdout = open(argv[2], O_WRONLY);
 close(2);
 fderr = open(argv[2], O_WRONLY);
 execlp("ls", "ls", "-l", 0);
 }
}
