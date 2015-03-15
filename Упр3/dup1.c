#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main() {
 int fd;
 fd = dup(1);
 printf("fd = %d\n", fd);
 write(1, "Hello", sizeof("Hello"));
 write(fd, "world", sizeof("world"));
 close(1);
 write(1, "No", 2);
 write(fd, "Yes\n", 5);
}
