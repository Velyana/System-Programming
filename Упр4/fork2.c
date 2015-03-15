#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main() {
 pid_t child_pid = fork();
 if(child_pid != 0) {
  printf("father");
  //wait();
  printf("done");
 } else {
  printf("son");
  int i;
  for(i = 0; i < 1000; i++);
 }
 printf("end");
 printf("\n");
}

