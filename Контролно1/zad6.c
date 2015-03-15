#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc, char* argv[]) {
 int fd, i = 0;
 char c, str[3];
 if((fd = open(argv[1], O_RDONLY)) == -1) {
  write(2, "cannot open file \n", 18);
  exit(1);
 }
 while(read(fd, &c, 1)) {
  ++i;
  sprintf(str, "%d", i);
  write(1, str, sizeof(str));
  write(1, "--->   ", 7);
  write(1, &c, 1);
  if(c == '\n') continue;
  while(c != '\n' && read(fd, &c, 1))
   write(1, &c, 1);
  if(c != '\n') exit(0);
 }
}
