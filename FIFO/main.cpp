#include "fifo.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <inputfile>" << std::endl;
        return 1;
    }

    std::string inputfile = argv[1];
    FIFO fifoScheduler(inputfile);

    fifoScheduler.calcWaitTime();
    fifoScheduler.calcTurnaroundTime();
    fifoScheduler.calcResponseTime();
    fifoScheduler.printResults();

    return 0;
}
