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

    int qi = 0;        // queue index
    int pind = -1;     // previous index keeps track of the processes those have gotten the cputime but still they are not finished yet so they need to be brought back into the ready queue at the last.
    int flag = 0;      // whether all the processes are executed
    int cputime = 0;   // keeps track of the current cputime(helps in calculating Completion time)
    int lasttime = -1; // keeps track of the previous cputime (i.e. before the most recent process was executed)

    int cind = 0; // current index that points the process in ready queue to be executed
    while(flag == 0)
    {
        // get new process in process queue;
        for(int i = 0; i < n; i++)
        {
            if(!((AT[i] <= cputime && AT[i] > lasttime)&& BT[i]> 0))continue; // these processes cant come in ready queue
            int fl = 0;
            for(int j = cind; j < qi; j++)
            {
                if(i == q[j]) // the process i is already in ready queue dont need to add it
                {
                    fl = 1;
                    break;
                }
            }
            if(fl == 0) // if the process is not found in ready queue then add it in the last index of the current ready queue
            {
                q[qi] = i; // adding the index in the queue
                qi++;   // incrementing the queue index;
            }
        }
        lasttime = cputime; // update the last cputime before the cputime gets updated;

        if(pind != -1)  // if previous ind in not -1 that means that there the process at queue index pind is not finished yet so it needs to be added back to the ready queue at the last
        {
            q[qi] = q[pind]; // adding the process in the ready queue
            qi++;   // incrementing the queue index
        }

        if(q[cind] == -1)   // if the queue index is pointing to no process that means the ready queue is empty but this does not mean all processes have finished execution, there maybe cases where the processes are yet to be Arrived so we have to keep the CPU idle and increment the cputime;
        {
            cputime+=ts;
        }

        if(BT[q[cind]] > ts) // if the burst time is bigger than time slice, the process can consume the entitiry of the time slice and still the process will not finish 
        {
            BT[q[cind]]-=ts;
            cputime += ts;
            pind = cind; // because the process is not yet finished as BT > 0 we must put in the ready queue again
        }
        else
        {
            cputime += BT[q[cind]]; // here the cputime = bt because the bt <= time slice that guatantees that the process will finish execution in this step
            BT[q[cind]] = 0;
            CT[q[cind]] = cputime;
            pind = -1; // previous index is -1 because it is not needed to be in the ready queue
        }
        cind++; // increment the current index of the ready queue

        int i = 0;
        for(i = 0; i < n; i++) // check whether all the processes finished execution
        {
            if(BT[i]  > 0)
                break;
        }
        if(i == n)
            flag = 1; // this will make the outer loop break signifying that all the processes have finished their execution
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