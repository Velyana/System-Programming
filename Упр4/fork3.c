#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main() {
 int i = 4;
 if(fork() == 0) {
  printf("i = %d\n", i);
  ++i;
  printf("i = %d\n", i);
 } else {
  --i;
  wait();
  printf("i = %d\n", i);
 }
 i++;
 printf("i = %d\n", i);
}
