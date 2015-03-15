#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main() {
 char c = '0', d = 'b';
 if(fork() != 0) {
  c = 'z';
  wait();
 } else {
  d = 'z';
  write(1, "\nc = ", 5);
  write(1, &c, 1);
 }
 write(1, "\nd = ", 5);
 write(1, &d, 1);
}
