#include "rr.cpp"

int main()
{
    int n;
    cout << "Enter Total Number of Processes: ";
    cin >> n;

    int arr_time[n], burst_time[n], temp_burst_time[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Details of Process " << i + 1 << endl;
        cout << "Arrival Time: ";
        cin >> arr_time[i];
        cout << "Burst Time: ";
        cin >> burst_time[i];
        temp_burst_time[i] = burst_time[i];
    }

    int time_slot;
    cout << "Enter Time Slot: ";
    cin >> time_slot;

    roundRobinScheduling(n, arr_time, burst_time, time_slot);

    return 0;
}
