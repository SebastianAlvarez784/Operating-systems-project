#include <iostream>
#include "Process.h"
#include "auth.h"
#include "VirtualMemory.h"

using namespace std;

int main() {
    cout << "OS is booting up...\n\n";

    // Authenticate user 
    if (!authenticateUser()) {
        cout << "Authentication failed. Exiting...\n";
        return 1;
    }

    cout << "Login successful. Initializing virtual memory...\n\n";

    // Initialize virtual memory with 64KB virtual space, 32KB physical space, and 4KB pages
    VirtualMemory vm(64 * 1024, 32 * 1024, 4 * 1024);

    // Create processes and allocate page tables
    Process p1(1, 0, 5, 2, 100, false);
    Process p2(2, 2, 3, 1, 200, true);
    Process p3(3, 4, 7, 3, 150, false);

    vm.allocatePageTable(p1.getPID());
    vm.allocatePageTable(p2.getPID());
    vm.allocatePageTable(p3.getPID());

    cout << "\nProcess page tables allocated.\n\n";

    // Simulating multiple memory accesses to trigger FIFO eviction
    cout << "Testing FIFO Page Replacement...\n";
    vm.translateAddress(p1.getPID(), 4096);  // Page 1
    vm.translateAddress(p1.getPID(), 8192);  // Page 2
    vm.translateAddress(p1.getPID(), 12288); // Page 3
    vm.translateAddress(p1.getPID(), 16384); // Page 4 
    vm.translateAddress(p1.getPID(), 20480); 
    vm.translateAddress(p1.getPID(), 24576); 
    vm.translateAddress(p1.getPID(), 28672); 
    vm.translateAddress(p1.getPID(), 32768); 
    vm.translateAddress(p1.getPID(), 36864); 
    vm.translateAddress(p1.getPID(), 40960); 
    vm.translateAddress(p1.getPID(), 45056); 
    vm.translateAddress(p1.getPID(), 49152); 


    // Simulate execution
    cout << "\nExecuting P1...\n";

    while (p1.getRemainingTime() > 0) {
        p1.decrementExecutionTime();
        cout << "P1 remaining time: " << p1.getRemainingTime() << "\n";
    }

    p1.setState("TERMINATED");

    cout << "\nFinal state of P1: " << p1.getState() << "\n\n";

    return 0;
}

