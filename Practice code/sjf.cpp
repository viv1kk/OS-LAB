// srtn
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of processes : ";
    cin>>n;
    int AT[n], BT[n], tempBT[n], CT[n], TAT[n], WT[n];
    cout<<"Enter the arrival time and burst time of each process :\n";
    for(int i = 0; i < n; i++)
    {
        cin>>AT[i]>>BT[i];
        tempBT[i] = BT[i]; 
    }
    int countProcessed = 0;
    int cputime = 0;
    float tot_wt = 0.0f, tot_tat = 0.0f;
    while(countProcessed != n)
    {
        int mn = 0;
        for(int i = 0; i < n; i++)
        {   if(BT[mn] == 0){ mn++; mn %= n; }
            if(AT[i] <= cputime && BT[i] < BT[mn] && BT[i] > 0 && BT[mn] > 0)
                mn = i;
        }
        BT[mn]--;
        cputime++;
        if(BT[mn] == 0)
        {
            countProcessed++;
            CT[mn] = cputime;
            TAT[mn] = CT[mn] - AT[mn];
            WT[mn] = TAT[mn] - tempBT[mn];
            tot_wt += (float)WT[mn];
            tot_tat += (float)TAT[mn];
        }
    }
    cout<<"\tProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i = 0; i < n; i++)
    {
        cout<<"\t"<<i+1<<"\t"<<AT[i]<<"\t"<<tempBT[i]<<"\t"<<CT[i]<<"\t"<<TAT[i]<<"\t"<<WT[i]<<"\n";
    }
    cout<<"Average TAT : "<<(tot_tat/(float)n)<<endl;
    cout<<"Average WT : "<<(tot_wt/(float)n)<<endl;
    return 0;
}