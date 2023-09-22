#include <iostream>
using namespace std;

void roundRobinScheduling(int n, int arr_time[], int burst_time[], int time_slot)
{
    int wait_time = 0, ta_time = 0, temp_burst_time[n], x = n;

    for (int i = 0; i < n; i++)
    {
        temp_burst_time[i] = burst_time[i];
    }

    int total = 0, counter = 0;

    cout << "Process ID Burst Time Turnaround Time Waiting Time\n";
    for (int total = 0, i = 0; x != 0;)
    {
        if (temp_burst_time[i] <= time_slot && temp_burst_time[i] > 0)
        {
            total = total + temp_burst_time[i];
            temp_burst_time[i] = 0;
            counter = 1;
        }
        else if (temp_burst_time[i] > 0)
        {
            temp_burst_time[i] = temp_burst_time[i] - time_slot;
            total += time_slot;
        }
        if (temp_burst_time[i] == 0 && counter == 1)
        {
            x--;
            cout << i + 1 << "\t\t" << burst_time[i] << "\t\t" << total - arr_time[i] << "\t\t" << total - arr_time[i] - burst_time[i] << "\n";
            wait_time = wait_time + total - arr_time[i] - burst_time[i];
            ta_time += total - arr_time[i];
            counter = 0;
        }
        if (i == n - 1)
        {
            i = 0;
        }
        else if (arr_time[i + 1] <= total)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }

    float average_wait_time = wait_time * 1.0 / n;
    float average_turnaround_time = ta_time * 1.0 / n;

    cout << "\nAverage Waiting Time: " << average_wait_time << endl;
    cout << "Average Turnaround Time: " << average_turnaround_time << endl;
}
