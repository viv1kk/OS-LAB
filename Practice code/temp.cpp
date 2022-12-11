#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the size of I/O queue size : ";
    cin>>n;
    cout<<"Enter the I/O Req :\n";
    vector<int>q(n, 0);
    for(int i = 1; i <= n; i++)
    {
        cin>>q[i];
    }
    int initHead;
    cout<<"Enter the initial Head Position : ";
    cin>>initHead;

    int count = 1;
    int seekTime = 0;
    while(count != n)
    {
        int mn = INT_MAX;
        int ind;
        for(int i = 0; i < n; i++)
        {
            if(mn > abs(q[i]-initHead))
            {
                mn = abs(q[i]-initHead);
                ind = i;
            }
        }
        cout<<mn<<" "<<initHead<<endl;
        seekTime += mn;
        initHead = q[ind];
        q[ind] = INT_MAX;
        count++;
    }
    cout<<"Total seektime = "<<seekTime;

    return 0;
}