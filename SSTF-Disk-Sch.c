#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(long*)a - *(long*)b );
}

int main()
{
    int n;
    printf("Input the I/O queue size : ");
    scanf("%d", &n);
    int q[(n+2)];
    q[0] = -100000; 
    q[n+1] = 10000;
    for(int i = 1; i <= n; i++)
    {
        printf("I/O Req-%d : ", i);
        scanf("%d", &q[i]);
    }
    int cylSize;
    printf("Enter the upperbound of cylinder : ");
    scanf("%d", &cylSize);
    int initHead;
    printf("Enter the initial head position : ");
    scanf("%d", &initHead);

    qsort(q, n+2, sizeof(long), cmpfunc);
    //find where the head lies in relation to data;

    // for(int i = 0; i < n+2; i++)
    // {
    //     printf("%d, ", q[i]);
    // }

    int ptr = 0; 
    int mn = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        if(mn > abs(q[i]-initHead))
        {
            mn = abs(q[i]-initHead);
            ptr = i;
        }
    }

    printf("THe init head = %d\n", q[ptr]);
    int lptr = ptr-1, rptr = ptr+1;
    int sum = abs(q[ptr]-initHead);

    for(int i = 1 ; i < n; i++)
    {
        int r = abs(q[rptr]-q[ptr]);
        int l = abs(q[lptr]-q[ptr]);
        if(r < l || (r == l && ptr > ((n+1)/2)))
        {
            sum += r;
            ptr = rptr;
            rptr = ptr+1;
        }
        else if(r > l || (r == l && ptr <= ((n+1)/2)))
        {
            sum += l;
            ptr = lptr;
            lptr = ptr-1;
        }
    }

    printf("\n%d", sum);
    
    return 0;
}

// 98 183 41 122 14 124 65 67