#include "Process.h"

Process::Process(int processID, int burstTime, string processStatus) {
    pid = processID;
    burst = burstTime;
    status = processStatus;
}

void Process::setStatus(string processStatus) { status = processStatus; }
int Process::getPID() const { return pid; }
int Process::getBurst() const { return burst; }
string Process::getStatus() const { return status; }

void Process::addPageMapping(int virtualPage, int physicalFrame) {
    pageTable[virtualPage] = physicalFrame;
}
//translate virtual adress to physical
int Process::translateAddress(int virtualAddress, int pageSize) {
    int pageNumber = virtualAddress / pageSize;
    int offset = virtualAddress % pageSize;

    if (pageTable.find(pageNumber) == pageTable.end()) {
        cerr << "Invalid page access: Page " << pageNumber << " not mapped.\n";
        return -1;
    }

    int physicalFrame = pageTable[pageNumber];
    return (physicalFrame * pageSize) + offset;
}

// Function definition map virtual pages to physical
void mapVirtualToPhysical(vector<Process>& processes, int pagesToMap, int& nextFreeFrame, int pageSize) {
    for (auto& process : processes) {
        for (int i = 0; i < pagesToMap; i++) {
            process.addPageMapping(i, nextFreeFrame++);
        }
//testing
        vector<int> testAddresses = { 0, pageSize + 1, 2 * pageSize + 500, 5 * pageSize };
        for (int address : testAddresses) {
            int physicalAddress = process.translateAddress(address, pageSize);
            if (physicalAddress != -1) {
                cout << "Process " << process.getPID() << " Virtual Address: " << address
                    << " -> Physical Address: " << physicalAddress << "\n";
            }
        }
    }
}
