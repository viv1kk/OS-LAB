#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the number of processes : ");
    scanf("%d", &n);

    int BT[n], tempBT[n], AT[n], PR[n], CT[n], q[n];
    printf("Enter the AT, BT, PR : \n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &AT[i],&BT[i], &PR[i]);
        tempBT[i] = BT[i];
        CT[i] = 0;
        q[i] = -1;
    }

    int qi = 0;      // queue index  points to the index where new incoming processes need to be stored
    int flag = 0;    
    int cputime = 0;   // keeps track of CPU time till all the processes are finished execution

    while(flag == 0)    // while all the processes are not finished
    {
        if(qi < n)  // if all processes not arrived in ready queue
        {
            //find the process that just arrived;
            for(int i = 0; i < n; i++)
            {
                if(AT[i] == cputime)
                {
                    q[qi] = i;
                    qi++;
                }
            }
        }

        int ind = 0;
        for(int i = 0; i < qi; i++) // initializing  ind with a valid value
        {
            if(q[i] != -1) 
            {
                ind = i;
                break;
            }

        }
        for(int i = 0; i < qi; i++)
        {
            if(q[i] == -1)
                continue;

            //find the process who have highest priority and if processes have equal priority then choose thee process with the smallest burst time
            if(PR[q[i]] == PR[q[ind]] && BT[q[i]] < BT[q[ind]])
            {
                ind = i;
            }
            if(PR[q[i]] < PR[q[ind]])
            {
                ind = i;
            }
        }

        if(qi < n) // single step execution because there maybe higher priority processes that can enter in the ready queue 
        {
            BT[q[ind]]--;
            cputime++;

            if(BT[q[ind]] == 0)
            {
                CT[q[ind]] = cputime; // storing the completition time of the process; 
                q[ind] = -1;    // removing the process from teh queue
            }
        }
        else // when all the processes are arrived then we can move to fully execute every process in one go because we alrady know the priority of each process
        {
            cputime+= BT[q[ind]];
            CT[q[ind]] = cputime;
            BT[q[ind]] = 0;
            q[ind] = -1;

            // check whether all processes are executed (here i checked ready queue but we can also check burst times)
            int i = 0;
            for(i = 0; i < n; i++)
            {
                if(q[i] != -1)
                    break;
            }
            if(i == n)
                flag = 1;
        }
    }
    int TAT[n], WT[n];
    float totTAT = 0.0f, totWT = 0.0f;
    for(int i = 0; i < n; i++)
    {
        TAT[i] = CT[i]-AT[i];
        WT[i] = TAT[i]-tempBT[i];

        totTAT += (float)TAT[i];
        totWT += (float)WT[i];
    }
    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i,AT[i], tempBT[i], PR[i], CT[i], TAT[i], WT[i]);
    }

    printf("atata %f wt %f", totTAT, totWT);
    printf("\nAverage TAT = %.2f\n", (totTAT/(float)n));
    printf("Average WT = %.2f\n", (totWT/(float)n));

    return 0;
}
