#include "simulator.h"

std::deque<pcb> readyQueue;

void rrScheduler(int quantum)
{
    long long totalTurnaroundTime = 0;
    long long totalWaitingTime = 0;
    long long currentTime = 0;

    while (!readyQueue.empty())
    {
        pcb &currentProcess = readyQueue.front();

        long long executionTime = std::min(quantum, static_cast<int>(currentProcess.getTotalTime()));

        currentProcess.setTotalTime(currentProcess.getTotalTime() - executionTime);

        // Calculate metrics
        long long waitingTime = currentTime;
        long long turnaroundTime = waitingTime + executionTime;
        long long responseTime = waitingTime;

        // Update totals for averages
        totalTurnaroundTime += turnaroundTime;
        totalWaitingTime += waitingTime;

        // Display output for the current process
        std::cout << "Process ID: " << currentProcess.getId()
                  << ", Burst Time: " << executionTime
                  << ", Turnaround Time: " << turnaroundTime
                  << ", Waiting Time: " << waitingTime
                  << ", Response Time: " << responseTime << std::endl;

        // Update current time
        currentTime += executionTime;

        if (currentProcess.getTotalTime() > 0)
        {
            // If the process hasn't finished, add it back to the queue
            readyQueue.push_back(currentProcess);
        }

        readyQueue.pop_front();
    }

    // Display average metrics
    int numProcesses = readyQueue.size();
    std::cout << "Average Turnaround Time: " << (double)totalTurnaroundTime / numProcesses << std::endl;
    std::cout << "Average Waiting Time: " << (double)totalWaitingTime / numProcesses << std::endl;
    std::cout << "Average Response Time: " << (double)totalWaitingTime / numProcesses << std::endl;
}
