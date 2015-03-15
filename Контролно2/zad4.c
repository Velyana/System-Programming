#include <fcntl.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    if(fork())
    {
    int status;
    wait(&status);
    
    printf("Status1 = %d\n", status);
    }
    else
    {
        if (fork())
        {
            int status;
            wait(&status);

            printf("Status2 = %d\n", status);
        }
        else
        {
            execlp("cal", "cal", 0);
        }
    execlp("date","date",0);
    }

    return 0;
}