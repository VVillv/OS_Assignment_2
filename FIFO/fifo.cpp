#include "simulator.h"

std::deque<pcb> readyQueue;

void fifoScheduler()
{
    long long totalTurnaroundTime = 0;
    long long totalWaitingTime = 0;
    long long currentTime = 0;

    while (!readyQueue.empty())
    {
        pcb &currentProcess = readyQueue.front();

        // Calculate metrics
        long long waitingTime = currentTime;
        long long turnaroundTime = waitingTime + currentProcess.getTotalTime();
        long long responseTime = waitingTime;

        // Update totals for averages
        totalTurnaroundTime += turnaroundTime;
        totalWaitingTime += waitingTime;

        // Display output for the current process
        std::cout << "Process ID: " << currentProcess.getId()
                  << ", Burst Time: " << currentProcess.getTotalTime()
                  << ", Turnaround Time: " << turnaroundTime
                  << ", Waiting Time: " << waitingTime
                  << ", Response Time: " << responseTime << std::endl;

        // Update current time
        currentTime += currentProcess.getTotalTime();

        readyQueue.pop_front();
    }

    // Display average metrics
    int numProcesses = readyQueue.size();
    std::cout << "Average Turnaround Time: " << (double)totalTurnaroundTime / numProcesses << std::endl;
    std::cout << "Average Waiting Time: " << (double)totalWaitingTime / numProcesses << std::endl;
    std::cout << "Average Response Time: " << (double)totalWaitingTime / numProcesses << std::endl;
}
