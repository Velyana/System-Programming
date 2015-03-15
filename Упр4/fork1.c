#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main() {
 pid_t child_pid = fork();
 if(child_pid != 0) {
 printf("My pid is %d and my parent pid is %d\n", getpid(), getppid());
 sleep(3);
 } else {
 printf("My pid is %d and my parent pid is %d\n", getpid(), getppid());
 }
}
