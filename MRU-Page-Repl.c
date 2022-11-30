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
    // int hist[np];

    for(int i = 0; i < np; i++)
    {
        p[i] = -1;
        // hist[i] = np-1-i; // for making initial priority in filling the pages
    }
    int pagefaults = 0;
    int pagehits = 0;
    int isfull = 0;
    int mru = 0;

    for(int i = 0; i < n; i++)
    {
        int currpage = s[i];
        int fl = 0;
        for(int j = 0; j < isfull; j++) // check all the pages that are filled
        {
            if(p[j] == currpage) // page hit
            {
                pagehits++;
                mru = j;
                fl = 1;
                break;
            }
        }
        if(isfull < np) // all pages are not filled
        {
            if(fl == 0) // page fault
            {
                pagefaults++;
                mru = isfull;
                p[isfull] = currpage;
                isfull++;
            }
        }
        else    // all pages are full
        {
            if(fl == 0) // page fault
            {
                p[mru] = currpage;
                pagefaults++;
            }
        }
    }

    printf("\nTotal Page faults : %d", pagefaults);
    printf("\nTotal Page hits : %d", pagehits);

    return 0;
}