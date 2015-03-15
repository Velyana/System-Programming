//Prenasochvane na standartnite vhod/izhod
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main(int argc, char* argv[]) {
 int fd, nbytr, nbytw, filesize = 0;
 char buf[25], str[25];
 close(0);
 if((fd = open(argv[1], 0)) == -1) {
  write(2, "Cannot open file for reading\n", 30);
  exit(1); 
 }
 while(nbytr = read(0, buf, 25)) {
  nbytw = write(1, buf, nbytr);
  if(nbytr = nbytw) filesize += nbytr;
  else write(2, "I/O Error! \n", sizeof("I/O Error!\n"));
 }
 write(1, "\nSize of file --> ", 18);
 sprintf(str, "%d", filesize);
 write(1, str, strlen(str));
 write(1, "characters\n", 12);
 printf("\nSize of file --> %d characters\n", filesize);
}
