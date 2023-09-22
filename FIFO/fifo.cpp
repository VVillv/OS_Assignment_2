#include <iostream>
using namespace std;

void fcfsScheduling(int pid[], int bt[], int n)
{
    int wt[15];
    wt[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
    cout << "Process ID Burst Time Waiting Time Turnaround Time\n";
    float twt = 0.0;
    float tat = 0.0;
    for (int i = 0; i < n; i++)
    {
        cout << pid[i] << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << bt[i] + wt[i] << "\n";
        twt += wt[i];
        tat += (wt[i] + bt[i]);
    }
    float att, awt;
    awt = twt / n;
    att = tat / n;
    cout << "Avg. waiting time= " << awt << endl;
    cout << "Avg. turnaround time= " << att << endl;
}
