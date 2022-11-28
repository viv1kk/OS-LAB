#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

int main()
{
    pid_t p;
    p = fork();
    if(p == 0)
    {
        printf("I am child with PID %d\n", getpid());
        printf("My Parent PID id %d\n", getppid());
    }
    else
    {
    sleep(5);
        printf("I am parent with PID %d\n", getpid());
        printf("Mey child PID id %d\n", p);
    }
    return 0;
}

// ./a.out &

//ps

