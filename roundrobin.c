#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of processes : ");
    scanf("%d", &n);

    int AT[n], BT[n], tempBT[n], CT[n], TAT[n], WT[n], q[n];

    printf("Enter the AT, BT : \n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d", &AT[i], &BT[i]);
        tempBT[i] = BT[i];
        CT[i] = 0;
        TAT[i] = 0;
        WT[i] = 0;
    }

    int ts;
    printf("Enter the time slice : ");
    scanf("%d", &ts);

    int qi = 0;
    int pind = -1;
    int flag = 0;
    int cputime = 0;
    int lasttime = -1;

    int cind = 0;
    while(flag == 0)
    {
        // get new process in process queue;
        for(int i = 0; i < n; i++)
        {
            if(!((AT[i] <= cputime && AT[i] > lasttime)&& BT[i]> 0))continue;
            int fl = 0;
            for(int j = cind; j < qi; j++)
            {
                if(i == q[j])
                {
                    fl = 1;
                    break;
                }
            }
            if(fl == 0)
            {
                q[qi] = i;
                qi++;
            }
        }
        lasttime = cputime;

        if(pind != -1)
        {
            q[qi] = q[pind];
            qi++;
        }

        if(q[cind] == -1)
        {
            cputime+=ts;
        }

        if(BT[q[cind]] > ts)
        {
            BT[q[cind]]-=ts;
            cputime += ts;
            pind = cind;
        }
        else
        {
            cputime += BT[q[cind]];
            BT[q[cind]] = 0;
            CT[q[cind]] = cputime;
            pind = -1; // previous index is -1 because it is not needed to be in the ready queue
        }
        cind++;

        int i = 0;
        for(i = 0; i < n; i++)
        {
            if(BT[i]  > 0)
                break;
        }
        if(i == n)
            flag = 1;
    }

    printf("\n");

    for(int i = 0; i < n; i++)
    {
        printf("%d, ", CT[i]);
    }

    printf("\n");
    float totTAT = 0.0f, totWT = 0.0f;
    for(int i = 0; i < n; i++)
    {
        TAT[i] = CT[i]-AT[i];
        WT[i] = TAT[i]-tempBT[i];

        totTAT += (float)TAT[i];
        totWT += (float)WT[i];
    }
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i,AT[i], tempBT[i], CT[i], TAT[i], WT[i]);
    }

    printf("\nAverage TAT = %.2f\n", (totTAT/(float)n));
    printf("Average WT = %.2f\n", (totWT/(float)n));

    return 0;
}