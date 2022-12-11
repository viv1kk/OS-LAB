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
    int hist[fs];
    int f[fs];
    for(int i = 0; i < fs; i++)
    {
        f[i] = -1;
        hist[i] = -i;
    }
    int pageFault = 0, pageHit = 0;
    for(int i = 0; i < n; i++)
    {
        int currPage = s[i];
        int flag = 0;
        for(int j = 0; j < fs; j++)
        {
            if(currPage == f[j])
            {
                flag = 1;
                pageHit++;
                hist[j] = 0;
                for(int k = 0; k < fs; k++)
                {
                    if(k == j) continue;
                    hist[k]--;
                }
            }
        }
        if(flag == 0)
        {
            pageFault++;
            // overwrite the least recently used frame;
            int ind = 0;
            for(int j = 0; j < fs; j++)
            {
                if(hist[ind] > hist[j])
                    ind = j;
            }
            f[ind] = currPage;
            hist[ind] = 0;
            for(int k = 0; k < fs; k++)
            {
                if(k == ind) continue;
                hist[k]--;
            }
        }
    }
    printf("\nTotal Page faults : %d", pageFault);
    printf("\nTotal Page hits : %d", pageHit);
    return 0;
}