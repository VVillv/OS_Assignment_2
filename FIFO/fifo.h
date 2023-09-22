#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>

#ifndef FIFO_H
#define FIFO_H

class FIFO
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

    FIFO(const std::string &inputfile);
    void calcWaitTime();
    void calcTurnaroundTime();
    void calcResponseTime();
    void printResults();
};

#endif