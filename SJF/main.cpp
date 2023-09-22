#include "sjf.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <inputfile>" << std::endl;
        return 1;
    }

    std::string inputfile = argv[1];
    SJF sjf(inputfile);
    sjf.calcWaitTime();
    sjf.calcTurnaroundTime();
    sjf.calcResponseTime();
    sjf.printResults();

    return 0;
}