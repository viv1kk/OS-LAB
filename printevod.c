#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int n;
    scanf("%d", &n);
    int x = fork();
    if(x == 0 && n&1)
        printf("Child Process : %d", n);
    else
        if(n&1 == 0)
            printf("Parent Process : %d", n);
    return 0;
}
