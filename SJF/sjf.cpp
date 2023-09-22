#include "sjf.h"

// Define static members
std::ifstream SJF::in;
std::vector<int> SJF::processId;
std::vector<int> SJF::burstTime;
std::vector<int> SJF::waitTime;
std::vector<int> SJF::turnaroundTime;
std::vector<int> SJF::responseTime;

SJF::SJF(const std::string &inputfile)
{
    // Open the input file
    in.open(inputfile);

    // Initialize averages
    avgWaitTime = 0.0;
    avgTurnaroundTime = 0.0;
    avgResponseTime = 0.0;

    // Check if the file is successfully opened
    if (!in.is_open())
    {
        std::cerr << "Error opening file." << std::endl;
        exit(EXIT_FAILURE);
    }

    // Read data from the file and initialize vectors
    while (std::getline(in, line))
    {
        int pid, bt;
        char comma;
        in >> pid >> comma >> bt;
        processId.push_back(pid);
        burstTime.push_back(bt);
    }

    // Close the file
    in.close();
}

void SJF::calcWaitTime()
{
    waitTime.resize(processId.size());
    waitTime[0] = 0;

    for (size_t i = 1; i < processId.size(); ++i)
    {
        waitTime[i] = burstTime[i - 1] + waitTime[i - 1];
    }
}

void SJF::calcTurnaroundTime()
{
    turnaroundTime.resize(processId.size());

    for (size_t i = 0; i < processId.size(); ++i)
    {
        turnaroundTime[i] = burstTime[i] + waitTime[i];
    }
}

void SJF::calcResponseTime()
{
    responseTime.resize(processId.size());
    responseTime[0] = 0;

    for (size_t i = 1; i < processId.size(); ++i)
    {
        responseTime[i] = burstTime[i - 1] + responseTime[i - 1];
    }
}

void SJF::printResults()
{
    std::cout << "Process ID\tBurst Time\tTurnaround Time\tWaiting Time\tResponse Time\n";

    for (size_t i = 0; i < processId.size(); ++i)
    {
        std::cout << processId[i] << "\t\t" << burstTime[i] << "\t\t" << turnaroundTime[i] << "\t\t"
                  << waitTime[i] << "\t\t" << responseTime[i] << "\n";

        avgWaitTime += waitTime[i];
        avgTurnaroundTime += turnaroundTime[i];
        avgResponseTime += responseTime[i];
    }

    avgWaitTime /= processId.size();
    avgTurnaroundTime /= processId.size();
    avgResponseTime /= processId.size();

    std::cout << "\nAverage Turnaround Time: " << avgTurnaroundTime << "\n";
    std::cout << "Average Waiting Time: " << avgWaitTime << "\n";
    std::cout << "Average Response Time: " << avgResponseTime << "\n";
}
