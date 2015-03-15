#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main() {
 int fd, i, j, k;
 int stdout_copy = dup(1);
 if((fd = creat("abc", 0666)) == -1) {
  write(2, "Cannot create file abc \n", 24);
  exit(1);
 }
 close(1);
 k = dup(fd);
 for(i = 0; i <= 15; ++i) 
  printf("i = %d\n", i);
// dup2(stdout_copy, 1);
// write(1, "sun", 3);
}
