#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the size of I/O queue size : ";
    cin>>n;
    cout<<"Enter the I/O Req :\n";
    vector<int>q(n+2, 0);
    for(int i = 1; i <= n; i++)
    {
        cin>>q[i];
    }
    int initHead;
    cout<<"Enter the initial Head Position : ";
    cin>>initHead;

    q[0] = -10000;
    q[n+1] = 10000;
    sort(q.begin(), q.end());

    int seektime = 0;
    int mn = INT_MAX;
    int ind = 0;
    for(int i = 1; i <=n; i++)
    {
        if(mn > abs(q[i]-initHead))
        {
            mn = abs(q[i]-initHead);
            ind = i;
        }
    }
     printf("The init head = %d\n", q[ind]);
    seektime += abs(q[ind]-initHead);

    int l = ind-1, r = ind+1;
    for(int i = 1; i < n; i++)
    {
        int vl = abs(q[ind]-q[l]);
        int vr = abs(q[ind]-q[r]);

        if(vr > vl)
        {
            seektime += vl;
            ind = l;
            l = ind-1;
        }
        else
        {
            seektime += vr;
            ind = r;
            r = ind+1;
        }
    }
    cout<<"Total SeekTime is "<<seektime<<endl;
    return 0;
}