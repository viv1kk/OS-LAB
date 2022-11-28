#include <stdio.h>
#include <limits.h>

int main()
{
    int n;
    printf("Enter the no of Processes : ");
    scanf("%d", &n);

    int AT[n];
    int BT[n];
    int CT[n];
    int tempBT[n]; // during the calculation of Completion time the array is being edited so we need to save the original BT

    printf("Enter the AT and BT of each Process : \n");
    for(int i = 0; i < n; i++)
    {
        printf("P%d = ", i);
        scanf("%d %d", &AT[i], &BT[i]);
        tempBT[i] = BT[i];
    }

    // Defining Queue;
    int q[n];
    int qi = 0;
    for(int i = 0; i < n; i++)
    {
        q[i] = -1;
    }


    int flag = 0;
    int ts = 0;
    while(flag == 0)
    {
        if(qi < n) // Not all process are in queue
        {
            for(int j = 0; j < n; j++)
            {
                // Search whether there is a new process arriving;
                // the loop will run till all the processes are in the ready queue;
                for(int i = 0; i < n; i++)
                {
                    if (AT[i] == ts)
                    {
                        // insert the process in queue
                        q[qi] = i;
                        qi++; // update the queue index
                    }
                }

                // find the process which is in the ready queue and have the smallest BT.

                int min = INT_MAX;
                int k = 0;
                for(int i = 0; i < n; i++)
                {
                    if(q[i] == -1)
                        continue;
                    if (BT[q[i]] < min)
                    {
                        min = BT[q[i]]; // reducing the bt,indicating process is being executed;
                        k = i;
                    }
                }
                --BT[q[k]];
                ++ts;
                if(BT[q[k]] == 0)
                {
                    CT[q[k]] = ts;
                    q[k] = -1;
                }
            }

        }
        else // all process are in queue
        {
            int min = INT_MAX;
            int k = 0;

            for(int i = 0; i < n; i++)
            {
                if(q[i] == -1)
                    continue;
                if(BT[q[i]] < min)
                {
                    min = BT[q[i]]; // Process with minimum BT, in the ready queue
                    k = i; // index of that process in the ready queue;
                }
            }
            ts += BT[q[k]];
            CT[q[k]] = ts;
            BT[q[k]] = 0;
            q[k] = -1;
        }
        int i = 0;
        for(i = 0; i < n; i++)
        {
            if(q[i] != -1)
                break;
        }
        if(i == n)
            flag = 1;
    }

    // Restoring the Burst Times from tempBT

    for(int i = 0; i < n; i++) BT[i] = tempBT[i];

    int WT[n], TAT[n];
    float ATAT = 0.0f;
    float AWT = 0.0f;
    for(int i = 0; i < n; i++)
    {
        TAT[i] = CT[i]-AT[i];
        WT[i] = TAT[i]-BT[i];
        ATAT += TAT[i];
        AWT += WT[i];
    }

    ATAT /= n;
    AWT /= n;

    printf("\tPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++)
    {
        printf("\tP%d\t%d\t%d\t%d\t%d\t%d\n", i, AT[i], BT[i], CT[i], TAT[i], WT[i]);
    }

    printf("\n Average Turnaround Time : %.2f", ATAT);
    printf("\n Average Waiting Time : %.2f\n", AWT);

    return 0;
}
