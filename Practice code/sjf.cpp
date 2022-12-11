// srtn
#include <bits/stdc++.h>
using namespace std;

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

    int q[n];

    for(int i = 0; i < n; i++)
    {
        q[i] = -1;
    }



    return 0;
}