#include "fifo.h"

std::ifstream FIFO::in;
std::vector<int> FIFO::processId;
std::vector<int> FIFO::burstTime;
std::vector<int> FIFO::waitTime;
std::vector<int> FIFO::turnaroundTime;
std::vector<int> FIFO::responseTime;

FIFO::FIFO(const std::string &inputfile)
{
    in.open(inputfile);
    if (!in.is_open())
    {
        std::cerr << "Error opening file: " << inputfile << std::endl;
        exit(1);
    }

    int id, burst;
    while (std::getline(in, line)) // Read each line into 'line'
    {

        // get the id
        std::string idstr = line.substr(0, line.find(","));
        id = std::stoi(idstr);
        // get the burst time
        std::string burststr = line.substr(line.find(",") + 1);
        burst = std::stoi(burststr);

        // append to respective vectors
        processId.push_back(id);
        burstTime.push_back(burst);
        waitTime.push_back(0);
        turnaroundTime.push_back(0);
        responseTime.push_back(0);
    }
    in.close(); // Don't forget to close the file
}

void FIFO::calcWaitTime()
{
    waitTime[0] = 0;
    for (size_t i = 1; i < processId.size(); ++i)
    {
        waitTime[i] = waitTime[i - 1] + burstTime[i - 1];
    }
}

void FIFO::calcTurnaroundTime()
{
    for (size_t i = 0; i < processId.size(); ++i)
    {
        turnaroundTime[i] = waitTime[i] + burstTime[i];
    }
}

void FIFO::calcResponseTime()
{
    responseTime[0] = 0;
    for (size_t i = 1; i < processId.size(); ++i)
    {
        responseTime[i] = waitTime[i];
    }
}

void FIFO::printResults()
{
    double totalWait = 0.0, totalTurnaround = 0.0, totalResponse = 0.0;

    std::cout << "Process ID | Burst Time | Wait Time | Turnaround Time | Response Time" << std::endl;

    for (size_t i = 0; i < processId.size(); ++i)
    {
        std::cout << processId[i] << "\t\t" << burstTime[i] << "\t\t" << waitTime[i] << "\t\t" << turnaroundTime[i] << "\t\t" << responseTime[i] << std::endl;

        totalWait += waitTime[i];
        totalTurnaround += turnaroundTime[i];
        totalResponse += responseTime[i];
    }

    avgWaitTime = totalWait / processId.size();
    avgTurnaroundTime = totalTurnaround / processId.size();
    avgResponseTime = totalResponse / processId.size();

    std::cout << std::endl
              << "Average Wait Time: " << avgWaitTime << std::endl;
    std::cout << "Average Turnaround Time: " << avgTurnaroundTime << std::endl;
    std::cout << "Average Response Time: " << avgResponseTime << std::endl;
}
