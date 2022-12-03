#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

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

    qsort(q, n, sizeof(int), cmpfunc);

    int ptr = 0;
    for(int i = 0; i < n; i++)
    {
        if(q[i] < initHead)
        {
            ptr = i;
        }
    }
    int sum = abs(q[ptr]-initHead);
    // go towards 0 (left)
    int t;
    for(int i = ptr; i > 0 ; i--)
    {
        sum += abs(q[i]-q[i-1]);
    }
    if( ptr != 0)
    {
        sum += q[0];
    }
    if(ptr+1 < n)
        sum += q[ptr+1];
    // go towards right 
    for(int i = ptr+1; i < n-1; i++)
    {
        sum += abs(q[i]-q[i+1]);
    }
    printf("\nSeek Time of the given I/O requests : %d, ", sum);
    return 0;
}

// 176 79 34 60 92 11 41 114