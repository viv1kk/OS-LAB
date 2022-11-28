#include <stdio.h>

typedef struct Process{
    int pid;
    int AT;
    int BT;
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

    printf("Input the Arrival Time and Burst Time of each Process : ");
    for(int i =0; i < n; i++)
    {
        p[i].pid = i;
        scanf("%d %d", &p[i].AT, &p[i].BT);
    }

    printf("\n");
    int i = 1;
    while(i < n)
    {
        int key = p[i].BT;
        Process k = p[i];
        int j = i-1;

        while(j >= 0 && p[j].BT > key)
        {
            p[j+1] = p[j];
            j--;
        }
        p[j+1] = k;
        i++;
    }

    int sum = 0;
    float ATAT= 0.0f;
    float AWT = 0.0f;
    for(int i = 0; i < n; i++)
    {
        sum += p[i].BT;
        p[i].CT = sum;
        p[i].TAT = p[i].CT-p[i].AT;
        p[i].WT = p[i].TAT-p[i].BT;
        ATAT += p[i].TAT;
        AWT += p[i].WT;
    }
    AWT /= n;
    ATAT /= n;

    printf("\tPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++)
    {
        printf("\tP%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].AT, p[i].BT, p[i].CT, p[i].TAT, p[i].WT);
    }
    printf("\nAverage Turnaround Time : %f", ATAT);
    printf("\nAverage Wating Time : %f\n", AWT);

    return 0;
}
