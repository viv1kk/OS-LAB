#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    if(fork() && fork())
    {
        fork();
    }
    printf("Hello");
    return 0;
}
