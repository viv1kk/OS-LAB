#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
     int pid = fork();
     if((pid&1) == 0)
        printf("process even pid");
    else
        printf("process odd pid");
    printf("%d",getpid());
    return 0;
}
