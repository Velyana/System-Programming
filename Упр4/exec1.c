#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main() {
 if(fork() != 0) {
  wait();
  printf("father");
 } else {
  if(execlp("ls", "ls", "-l", 0) != -1)
    printf("son");
 }
}
