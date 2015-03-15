#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main() {
 int i;
 for(i = 0; i < 3; i++) {
  printf("%d\n", i);
  execlp("ls", "ls", 0);
  printf("%d\n", i);
 }
}
