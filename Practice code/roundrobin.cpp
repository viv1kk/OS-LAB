#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of Processes : ";
    cin>>n;
    int AT[n], BT[n], PR[n], tempBT[n], CT[n], TAT[n], WT[n];

    cout<<"Enter Arrival Time, Burst Time : \n";
    for(int i = 0; i < n; i++)
    {
        cin>>AT[i]>>BT[i];
        tempBT[i] = BT[i];
    }
    int timeslice = 0;
    cout<<"Enter time slice : ";
    cin>>timeslice;
    int done = 0;
    int cputime = 0;
    queue<int>q; // ready queue
    vector<int>visited(n, 0);
    float tot_wt = 0.0f, tot_tat = 0.0f;
    int flagInd = -1; 
    while(done == 0)
    {
        for(int i = 0; i < n; i++)
        {
            if(AT[i] <= cputime && visited[i] == 0){ q.push(i); visited[i] = 1; } // process which are not yet visited and whose arrival time <= cputime
        }
        if(flagInd != -1) q.push(flagInd); // the previous unfinished process inserted in queue after all newly arrived processes are inserted
        if(q.empty()){cputime++; continue;}
        int currProcess = q.front();
        if(BT[currProcess] > timeslice)
        {
            cputime += timeslice;
            BT[currProcess] -= timeslice;
            q.pop(); // remove from the front (but this process need to be put back after all the newly arrived process are inserted in the queue)
            flagInd = currProcess; // this process need to be put back in queue
        }
        else
        {
            cputime+=BT[currProcess];
            flagInd = -1; // the process is finished so no need to put it in the queue
            BT[currProcess] = 0;
            CT[currProcess] = cputime;
            TAT[currProcess] = CT[currProcess]-AT[currProcess];
            WT[currProcess] = TAT[currProcess]-tempBT[currProcess];
            tot_wt += (float)WT[currProcess];
            tot_tat += (float)TAT[currProcess];
            q.pop();
        }
        // Check if all the processes are finsished 
        done = 1; 
        for(int i = 0; i < n; i++)
        {
            if(BT[i] != 0)
            { done = 0; break; }
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