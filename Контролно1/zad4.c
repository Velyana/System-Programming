#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#define CMD "wc -l $PWD"

int main() {
 int i = 2;
 if(fork() == 0) {
  ++i; 
  exit(0);
 } else {
  if(execlp(CMD, CMD, 0) == -1) {
   --i;
   wait();
   printf("i = %d\n", i);
 } else
    printf("i = %d\n", i);
 }
}
