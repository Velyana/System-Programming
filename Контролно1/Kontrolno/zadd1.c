#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc, char* argv[]) {
 char c;
 char buf[50];
 int length;
 int count = 0;
 int fd1 = open(argv[1], O_RDWR | O_CREAT);
 int fd2 = open(argv[2], O_WRONLY);
 lseek(fd1, 0, SEEK_END);
 while(length = read(0, buf, 50)) {
  write(fd1, buf, length);
 }
 lseek(fd2, 0, SEEK_SET); 
 while(read(fd1, &c, 1)) {
  if(c == '\t' && count <= atoi(argv[3])) {
   write(fd2, ">>>", 3);
   count++;
  }
  write(fd2, &c, 1);  
 }
}
