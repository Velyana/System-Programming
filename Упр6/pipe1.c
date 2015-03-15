#include<stdio.h>
#include<unistd.h>
int main() {
 char buf[16];
 int fd[0];
 if(pipe(fd)==-1) {
  write(2, "Unable to pipe", 14);
  }
  if(fork() == 0) {
    close(fd[1]);
    read(fd[0], buf, 16);
    close(fd[0]);
    return 0;
  } else {
    close(fd[0]);
    write(fd[1], "Hello", 5);
    close(fd[1]);
    wait(NULL);
    return 0;
  }
}
