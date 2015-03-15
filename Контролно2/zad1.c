#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
int main(int argc, char* argv[]) {
    int fd[0];
    if(pipe(fd) == -1) {
        write(2, "unable to pipe", 14);
    }
    if(fork() == 0) {
        close(1);
        dup(fd[1]);

        close(fd[0]);
        close(fd[1]);

        execlp("ls", "ls", "-l", 0);
    } else {
        close(0);
        dup(fd[0]);

        close(fd[0]);
        close(fd[1]);

        int f = open(argv[1], O_WRONLY | O_CREAT, 0777);

        close(1);
        dup(f);

        execlp("wc", "wc", "-c", 0);
    }
}