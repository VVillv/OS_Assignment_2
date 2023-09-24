#include "rr.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <quantum> <inputfile>" << std::endl;
        return 1;
    }

    int quantum = std::stoi(argv[1]);
    std::string inputfile = argv[2];
    RR rrScheduler(inputfile);

    rrScheduler.calcRoundRobin(quantum);
    rrScheduler.printResults();

    return 0;
}