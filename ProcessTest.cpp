#include <iostream>
#include <vector>
#include "process.h"  

using namespace std;

// Function to test the Process class and state transitions
void testProcessSimulation() {
    Process p1(1, 0, 5, 2, 100, true);  // PID=1, Arrival Time=0, Burst Time=5, Priority=2, Memory=100, IO operations=true
    Process p2(2, 1, 3, 1, 150, false); // PID=2, Arrival Time=1, Burst Time=3, Priority=1, Memory=150, IO operations=false
    Process p3(3, 2, 4, 3, 200, true);  // PID=3, Arrival Time=2, Burst Time=4, Priority=3, Memory=200, IO operations=true

    vector<Process> processes = {p1, p2, p3};  // Create a vector to store the processes

    cout << "\nInitial Process States:\n";
    for (const auto& p : processes) {
        p.printInfo();  // Print the initial states of the processes
    }

    // state transitions
    for (auto& p : processes) p.updateState(ProcessState::READY);
    processes[0].updateState(ProcessState::RUNNING);

    for (int i = 0; i < 2; ++i) processes[0].executeOneUnit();  // Simulate running for 2 units of time

    processes[0].updateState(ProcessState::WAITING);  
    processes[1].updateState(ProcessState::RUNNING);

    for (int i = 0; i < 3; ++i) processes[1].executeOneUnit();  // Simulate running for 3 units of time

    processes[1].updateState(ProcessState::TERMINATED);  

    cout << "\nFinal Process States:\n";
    for (const auto& p : processes) {
        p.printInfo();  // Print final states of the processes
    }
}
