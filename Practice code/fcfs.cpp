#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int, int>&a, pair<int, int>&b)
{
    if(a.first == b.first) return false;
    return a.first < b.first;
}
int main()
{
    int n;
    cout<<"Enter the number of processes : ";
    cin>>n;
    vector<pair<int, int>> p(n);
    int CT[n], TAT[n], WT[n];
    cout<<"Enter the arrival time and burst time of each process :\n";
    for(int i = 0; i < n; i++)
    {
        int t1, t2;
        cin>>t1>>t2;
        p[i].first = t1;
        p[i].second = t2;
    }
    sort(p.begin(), p.end(), comp);

    int ts = p[0].first;
    float tot_wt = 0.0f, tot_tat = 0.0f;
    for(int i = 0; i < n; i++)
    {
        ts+=p[i].second;
        CT[i] = ts;
        TAT[i] = CT[i]-p[i].first;
        WT[i] = TAT[i]-p[i].second;
        tot_wt += (float)WT[i];
        tot_tat += (float)TAT[i];
    }
    cout<<"\tProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i = 0; i < n; i++)
    {
        cout<<"\t"<<i+1<<"\t"<<p[i].first<<"\t"<<p[i].second<<"\t"<<CT[i]<<"\t"<<TAT[i]<<"\t"<<WT[i]<<"\n";
    }
    cout<<"Average TAT : "<<(tot_tat/(float)n)<<endl;
    cout<<"Average WT : "<<(tot_wt/(float)n)<<endl;
    return 0;
}