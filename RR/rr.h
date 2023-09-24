#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>

#ifndef RR_H
#define RR_H

class RR
{
private:
    std::string line;

public:
    double avgWaitTime;
    double avgTurnaroundTime;
    double avgResponseTime;
    static std::ifstream in;
    static std::vector<int> processId;
    static std::vector<int> burstTime;
    static std::vector<int> waitTime;
    static std::vector<int> turnaroundTime;
    static std::vector<int> responseTime;

    RR(const std::string &inputfile);
    void calcRoundRobin(int quantum);
    void printResults();
};

#endif
