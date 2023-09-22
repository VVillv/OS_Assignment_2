#include <iostream>
using namespace std;

void sjfScheduling(int bt[], int n)
{
    int p[20], wt[20], tat[20], total = 0, totalT = 0, pos, temp;

    for (int i = 0; i < n; i++)
    {
        p[i] = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        pos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (bt[j] < bt[pos])
                pos = j;
        }
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    wt[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (int j = 0; j < i; j++)
            wt[i] += bt[j];
        total += wt[i];
    }

    float avg_wt = (float)total / n;
    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        totalT += tat[i];
        cout << "p" << p[i] << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }

    float avg_tat = (float)totalT / n;
    cout << "\nAverage Waiting Time = " << avg_wt << endl;
    cout << "Average Turnaround Time = " << avg_tat << endl;
}
