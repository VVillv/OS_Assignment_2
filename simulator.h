#include "pcb.h"
#include <vector>
#include <deque>

// Function to load PCBs from the datafile into the ready queue
void loadPCBs(const std::string &datafile);

// Function to display the output for each process and average metrics
void displayOutput(const std::vector<pcb> &processes);

// Scheduling algorithms
void fifoScheduler();
void sjfScheduler();
void rrScheduler(int quantum);
 