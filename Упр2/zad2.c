#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main() {
 char buf[20];
 int fd1 = open("fff", 0);
 int fd2 = open("fff", 1);
 int fd3 = open("fff", 2);
 write(fd2, "hello world", 11);
 read(fd3, buf, 6);
 write(1, buf, 6);
 read(fd1, buf, 5);
 write(1, buf, 5);
 write(fd3, "chil", 4);
 write(fd2, "!!!", 3);
 read(fd1, buf, 9);
 write(1, buf, 9); 
 return 0;
}
