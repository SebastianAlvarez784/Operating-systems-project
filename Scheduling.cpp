#include <iostream>
#include <queue>
#include <vector>
#include "Scheduling.h"

using namespace std;

// First-Come, First-Served (FCFS) Scheduling
void FCFS(int& nextFreeFrame, int pageSize) {
    queue<Process> readyQueue;
    int processID = 0, cycles = 5;

    // Create and push processes to the ready queue
    for (int i = 0; i < cycles; i++) {
        if ((rand() % 10) > 5) {
            Process process(processID++, rand() % 10 + 1);
            process.setStatus("Ready");
            readyQueue.push(process);
        }
    }

    // Ensure at least one process exists
    if (readyQueue.empty()) {
        Process process(processID++, rand() % 10 + 1);
        process.setStatus("Ready");
        readyQueue.push(process);
    }

    // Process FIFO order execution
    while (!readyQueue.empty()) {
        Process process = readyQueue.front();
        readyQueue.pop();

        cout << "Processing FCFS: PID " << process.getPID() << ", Burst: " << process.getBurst() << endl;

        vector<Process> processes = { process };
        mapVirtualToPhysical(processes, 4, nextFreeFrame, pageSize);  
    }
}
