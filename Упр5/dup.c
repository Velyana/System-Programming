#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main() {
 int fd;
 fd = dup(1);
 printf("fd = %d\n", fd);
 write(1, "Hello", 5);
 write(fd, " guys\n", 6);
 write(1, "and Goofbye\n", 13);
 close(1);
 write(1, "No\n", 3);
 write(fd, "Yes\n", 4);
}
