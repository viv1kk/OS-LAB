#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Input the I/O queue size : ");
    scanf("%d", &n);
    int q[n];
    for(int i = 0; i < n; i++)
    {
        printf("I/O Req-%d : ", i+1);
        scanf("%d", &q[i]);
    }
    int cylSize;
    printf("Enter the upperbound of cylinder : ");
    scanf("%d", &cylSize);
    int initHead;
    printf("Enter the initial head position : ");
    scanf("%d", &initHead);

    int seektime = abs(initHead-q[0]);

    for(int i = 0; i < n-1; i++)
    {
        seektime += abs(q[i]-q[i+1]);
    }
    printf("\nTotal Seektime : %d", seektime);
    return 0;
}