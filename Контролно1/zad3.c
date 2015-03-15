#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main() {
 int i = 4;
 if (fork() == 0) {
  ++i;
  printf("i = %d\n", i);
 } else {
  --i;
  exit(0);
  wait();
  if(execlp("ls", "ls", "-l", 0) == -1)
   i += 1;
  else
   printf("i = %d\n", i);
 }
 printf("i = %d\n", i);
}
