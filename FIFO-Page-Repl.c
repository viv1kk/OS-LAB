#include <stdio.h>

int main()
{
    int n, np;
    printf("Enter the size of reference string : ");
    scanf("%d", &n);
    int s[n];
    printf("Enter the reference string : ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
    }

    printf("Enter the number of pages : ");
    scanf("%d", &np);
    int p[np];

    for(int i = 0; i < np; i++)
    {
        p[i] = -1;
    }
    int pagefaults = 0;
    int pagehits = 0;
    int repind = 0;
    for(int i = 0; i < n; i++)
    {
        int currentp = s[i];
        
        //check if the page is available in the mem;
        int flag = 0;
        for(int j = 0; j < np; j++)
        {
            if(p[j] == currentp) // page hit
            {
                flag = 1;
                pagehits++;
                break;
            }
        }
        if(flag == 0) // page fault
        {
            p[repind] = currentp;
            pagefaults++;
            repind = (repind+1)%np;
        }
    }
    printf("\nTotal Page faults : %d", pagefaults);
    printf("\nTotal Page hits : %d", pagehits);
    return 0;
}