#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main() {
 int fd, fdr, l1, l2, ub1, ub2;
 char buf[25];
 fd = open("f1", O_WRONLY);
 fdr = open("f1", O_RDONLY);
 l1 = lseek(fd, -3, SEEK_END);
 ub1 = write(fd, "xyzw", 4);
 l2 = lseek(fd, 4, SEEK_SET);
 write(fd, "12", 2);
 lseek(fdr, 0, SEEK_SET);
 ub2 = read(fdr, buf, 20);
 write(1, buf, ub2);
}
