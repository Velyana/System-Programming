#include<stdio.h>
#include<unistd.h>
int main(int argc, char* argv[]) {
    if(fork() != 0) {
        int status;
        wait(&status);
        if(status != 0)
            printf("No");
        else
            printf("Yes");
    }
    else {
        int fd[0];
        if(pipe(fd) == -1)
            write(2, "unable to pipe", 14);
        if(fork() == 0) {
            close(fd[0]);
            close(1);
            dup(fd[1]);
            execlp("ls", "ls", 0);
        }
        else {
            close(fd[1]);
            close(0);
            dup(fd[0]);
            execlp("grep", "grep", argv[1], 0);
        }
    }
}