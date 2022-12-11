#include <iostream>
using namespace std;

// Lower the Number Higher the priority
int main()
{
    int n;
    cout << "Enter Number of Process: ";
    cin >> n;
    int at[100], bt[100], p[100], temp[100], wt[100], tat[100], ct[100];
    cout << "Arrival Time Burst Time and Priority Time: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> at[i] >> bt[i] >> p[i];
    }

    int i, j, min, count = 0, time;
    double avg = 0, tt = 0, end;

    for (i = 0; i < n; i++)
        temp[i] = bt[i];

    p[n] = 10000;
    for (time = 0; count != n; time++)
    {
        min = n;
        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && p[i] < p[min] && bt[i] > 0)
                min = i;
        }
        bt[min]--;

        if (bt[min] == 0)
        {
            count++;
            end = time + 1;
            ct[min] = end;
            wt[min] = end - at[min] - temp[min];
            tat[min] = end - at[min];
        }
    }
    for (i = 0; i < n; i++)
    {
        avg = avg + wt[i];
        tt = tt + tat[i];
    }
    cout << "\n\nAverage waiting time time = " << avg / n<<endl;
    cout << " Average turnaround time time = " << tt/n<<endl;
}