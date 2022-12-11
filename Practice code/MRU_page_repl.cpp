#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, fs;  
    cout<<"Enter the size of the reference string : ";
    cin>>n;
    int s[n];
    cout<<"Enter the Reference string : ";
    for(int i = 0; i < n; i++)
    {
        cin>>s[i];
    }
    cout<<"Enter the number of frames : ";
    cin>>fs;
    vector<int>f(fs, -1);
    int mru = 0, pageFault = 0, pageHit = 0;
    int frameFull = 0;
    for(int i = 0; i < n ; i++)
    {
        int currPage = s[i];
        int flag = 0;
        for(int j = 0; j < fs; j++)
        {
            if(f[j] == currPage)
            {
                pageHit++;
                mru = j;
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            pageFault++;
            if(frameFull != fs)
            {
                for(int j = 0; j < fs; j++)
                    if(f[j] == -1) break;
                f[frameFull] = currPage;
                frameFull++;
                mru = frameFull;
            }
            else
                f[mru] = currPage;
        }
    }
    printf("\nTotal Page faults : %d", pageFault);
    printf("\nTotal Page hits : %d", pageHit);
    return 0;
}