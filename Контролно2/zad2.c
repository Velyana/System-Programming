#include<stdio.h>
#include<fcntl.h>
void main(int argc, char* argv[]) {
    int fdi, fdo, k, count, i = 0, status;
    char buff[40], c;
    if((fdi = open("file.txt", 2)) == -1) {
        printf("\nCannot open\n");
        exit(1);
    }
    if((fdo = open(argv[1], O_CREAT|O_TRUNC|O_RDWR, 0666)) == -1)
    {
        printf("\nCannot open\n");
        exit(1);
    }
    if(fork() == 0) {
        k = dup(1);
        close(1);
        dup(fdi);
        count = read(fdi, buff, 40);
        c = buff[i++];
        if(c <= '0' || c >= '9') {
            while(buff[i++] != '\n' && i < count) {
                write(1, "*", 1);
            }
            write(1, "\n", 1);
            close(1);
            dup(k);
            write(1, "*\n", 2);
        }
        else {
            write(1, buff, count);
            close(1);
            dup(k);
            write(1, "*\n", 2);
        }
        write(fdo, buff, 7);
        write(fdo, "*\n", 2);
        close(fdi);
        close(fdo);
    }
    else {
        wait(&status);
        close(1);
        dup(fdo);
        execlp("wc", "wc", "-l", "file.txt", 0);
        execlp("cat", "cat", argv[1], 0);
    }
}