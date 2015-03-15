#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main() {
 char buf[25];
 creat("f1", 0644);
 int fd1 = open("f1", O_RDONLY);
 int fd2 = open("f1", O_WRONLY);
 int fd3 = open("f1", O_RDWR);
 write(fd2, "Hello world", 11);
 int n = read(fd3, buf, 6);
 write(1, buf, n);
 n = read(fd1, buf, 5);
 write(1, buf, 5);
 write(fd3, "chi", 3);
 write(fd2, "!!!", 3);
 n = read(fd1, buf, 25);
 write(1, buf, n);
}
