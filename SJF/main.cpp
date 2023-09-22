#include "sjf.cpp"

int main()
{
    int n;
    cout << "Enter number of process:";
    cin >> n;

    int bt[20];
    cout << "\nEnter Burst Time:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "p" << i + 1 << ":";
        cin >> bt[i];
    }

    sjfScheduling(bt, n);

    return 0;
}
