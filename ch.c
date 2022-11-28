#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
printf("HELLO!!");
fork();
printf("%d", getpid());
return 0;
}
