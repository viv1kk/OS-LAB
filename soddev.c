#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int x = 10;
    int n = fork();
    if(n == 0)
    {
        int sum = 0;
        for(int i = 0; i < 10; ++i)
        {
            if(i&1)
               sum += i;
        }
        printf("From Child Process : %d, \n", sum);
    }
    else
    {
        int sum = 0;
        for(int i = 0; i < 10; ++i)
        {
            if(!(i&0))
               sum += i;
        }
        printf("From Parent Process : %d, \n", sum);
    }
    return 0;
}
