#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the size of I/O queue size : ";
    cin>>n;
    cout<<"Enter the I/O Req :\n";
    int q[n];
    for(int i = 0; i < n; i++)
    {
        cin>>q[i];
    }
    int initHead;
    cout<<"Enter the initial Head Position : ";
    cin>>initHead;

    int seekTime = abs(initHead-q[0]);

    for(int i = 0; i < n-1; i++)
    {
        seekTime += abs(q[i]-q[i+1]);
    }
    
    cout<<"Total SeekTime is "<<seekTime<<endl;
    return 0;
}