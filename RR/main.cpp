#include "rr.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <inputfile>" << std::endl;
        return 1;
    }

    std::string inputfile = argv[1];
    RR rrScheduler(inputfile);

    rrScheduler.calcRoundRobin();
    rrScheduler.printResults();

    return 0;
}
