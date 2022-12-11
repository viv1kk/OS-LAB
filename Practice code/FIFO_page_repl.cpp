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

    int ind = 0;
    int pageHit = 0;
    int pageFault = 0;
    for(int i = 0; i < n; i++)
    {
        int currPage = s[i];
        int flag = 0;
        for(int j = 0; j < fs; j++)
        {
            if(f[j] == currPage){
                pageHit++;
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            pageFault++;
            f[ind] = currPage;
            ind++;
            ind %= fs;
        }
    }
    cout<<"Total Page Hits : "<<pageHit<<endl;
    cout<<"Total Page Faults : "<<pageFault<<endl;
    return 0;
}