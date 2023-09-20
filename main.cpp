#include "simulator.h"
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cerr << "Usage: ./program_name [fifo|sjf|rr] [quantum] datafile" << std::endl;
        return 1;
    }

    std::string schedulerType = argv[1];
    std::string datafile;
    int quantum = 0;

    if (schedulerType == "fifo" || schedulerType == "sjf")
    {
        datafile = argv[2];
    }
    else if (schedulerType == "rr")
    {
        quantum = std::stoi(argv[2]);
        datafile = argv[3];
    }
    else
    {
        std::cerr << "Invalid scheduler type!" << std::endl;
        return 1;
    }

    loadPCBs(datafile);

    if (schedulerType == "fifo")
    {
        fifoScheduler();
    }
    else if (schedulerType == "sjf")
    {
        sjfScheduler();
    }
    else if (schedulerType == "rr")
    {
        rrScheduler(quantum);
    }

    return 0;
}
