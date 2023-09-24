#include "rr.h"

std::ifstream RR::in;
std::vector<int> RR::processId;
std::vector<int> RR::burstTime;
std::vector<int> RR::waitTime;
std::vector<int> RR::turnaroundTime;
std::vector<int> RR::responseTime;

RR::RR(const std::string &inputfile)
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

#include "rr.h"

void RR::calcRoundRobin(int quantum)
{
    int total = 0;

    while (true)
    {
        bool allProcessesCompleted = true;

        for (size_t i = 0; i < processId.size(); ++i)
        {
            if (burstTime[i] > 0)
            {
                allProcessesCompleted = false;

                if (burstTime[i] <= quantum)
                {
                    total += burstTime[i];
                    waitTime[i] = total - burstTime[i];
                    turnaroundTime[i] = total;
                    if (responseTime[i] == 0) // Only update response time if it's not set yet
                        responseTime[i] = total - burstTime[i];

                    burstTime[i] = 0;
                }
                else
                {
                    total += quantum;
                    burstTime[i] -= quantum;
                    if (responseTime[i] == 0) // Only update response time if it's not set yet
                        responseTime[i] = total - quantum;
                }
            }
        }

        if (allProcessesCompleted)
            break;
    }
}

void RR::printResults()
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
