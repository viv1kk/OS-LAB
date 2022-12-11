#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of Processes : ";
    cin>>n;
    int AT[n], BT[n], PR[n], tempBT[n], CT[n], TAT[n], WT[n];

    cout<<"Enter Arrival Time, Burst Time And Priority : \n";
    for(int i = 0; i < n; i++)
    {
        cin>>AT[i]>>BT[i]>>PR[i];
        tempBT[i] = BT[i];
    }
    int countProcessed = 0;
    int cputime = 0;
    float tot_wt = 0.0f, tot_tat = 0.0f;
    while(countProcessed != n)
    {
        // get the most appropriate process
        int pro = -1;
        for(int i = 0; i < n; i++)
        {
            if(AT[i] <= cputime && BT[i] > 0)
            {
                if(pro == -1) pro = i;
                else if(PR[i] < PR[pro]) pro = i;
            }
        }
        BT[pro]--;
        cputime++;
        if(BT[pro]<=0)
        {
            countProcessed++;
            CT[pro]=cputime;
            TAT[pro]=CT[pro]-AT[pro];
            WT[pro]=TAT[pro]-tempBT[pro];
            tot_wt+=(float)WT[pro];
            tot_tat+=(float)TAT[pro];
        }
    }
    cout<<"\tProcess\tAT\tBT\tPR\tCT\tTAT\tWT\n";
    for(int i = 0; i < n; i++)
    {
        cout<<"\t"<<i+1<<"\t"<<AT[i]<<"\t"<<BT[i]<<"\t"<<PR[i]<<"\t"<<CT[i]<<"\t"<<TAT[i]<<"\t"<<WT[i]<<"\n";
    }
    cout<<"Average TAT : "<<(tot_tat/(float)n)<<endl;
    cout<<"Average WT : "<<(tot_wt/(float)n)<<endl;
    return 0;
}