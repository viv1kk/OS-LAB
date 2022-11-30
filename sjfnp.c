#include <stdio.h>
#include <limits.h>
typedef struct Process{
    int pid;
    int AT;
    int BT;
    int tBT;
    int CT;
    int TAT;
    int WT;
}Process;

int main()
{
    int n;
    printf("Enter the number of Processes : ");
    scanf("%d", &n);

    Process p[n];

    printf("Input the Arrival Time and Burst Time of each Process : \n");
    for(int i = 0; i < n; i++)
    {
        p[i].pid = i;
        scanf("%d %d", &p[i].AT, &p[i].BT);
        p[i].tBT = p[i].BT;
    }

    int cputime = 0;
    int flag = 0;
    // find that process which is having arrival time <= cputime and having the minimum bursttime that is > 0
    
    while(flag == 0)
    {
        int indPr;
        int mnbt = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            if(p[i].AT <= cputime && p[i].BT < mnbt && p[i].BT > 0)
            {
                mnbt = p[i].BT;
                indPr = i;
            }
        }

        if(p[indPr].AT > cputime || p[indPr].BT < 1)
        {
            cputime++;
            continue;
        }
        cputime += p[indPr].BT;
        p[indPr].CT = cputime;
        p[indPr].BT = 0;

        flag = 1;
        for(int i = 0; i < n; i++){
            if(p[i].BT > 0)
            {
                flag = 0;
                break;
            }
        }
    }
    float ATAT= 0.0f;
    float AWT = 0.0f;
    for(int i = 0; i < n; i++)
    {
        p[i].TAT = p[i].CT-p[i].AT;
        p[i].WT = p[i].TAT-p[i].tBT;
        ATAT += p[i].TAT;
        AWT += p[i].WT;
    }
    AWT /= n;
    ATAT /= n;

    printf("\tPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++)
    {
        printf("\tP%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].AT, p[i].tBT, p[i].CT, p[i].TAT, p[i].WT);
    }
    printf("\nAverage Turnaround Time : %f", ATAT);
    printf("\nAverage Wating Time : %f\n", AWT);

    return 0;
}
