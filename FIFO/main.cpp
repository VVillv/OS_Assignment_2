#include "fifo.cpp"

int main()
{
    int pid[15];
    int bt[15];
    int n;

    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter process id of all the processes: ";
    for (int i = 0; i < n; i++)
    {
        cin >> pid[i];
    }
    cout << "Enter burst time of all the processes: ";
    for (int i = 0; i < n; i++)
    {
        cin >> bt[i];
    }

    // Call the FCFS scheduling function
    fcfsScheduling(pid, bt, n);

    return 0;
}
