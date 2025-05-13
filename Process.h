#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Process {
private:
    int pid, burst;
    string status;
    map<int, int> pageTable;

public:
    Process(int processID, int burstTime, string processStatus = "New");

    void setStatus(string processStatus);
    int getPID() const;
    int getBurst() const;
    string getStatus() const;

    void addPageMapping(int virtualPage, int physicalFrame);
    int translateAddress(int virtualAddress, int pageSize);
};

// Function declaration 
void mapVirtualToPhysical(vector<Process>& processes, int pagesToMap, int& nextFreeFrame, int pageSize);

#endif
