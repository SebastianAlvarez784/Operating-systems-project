#include <iostream>
#include "auth.h"      
#include "Scheduling.h"

using namespace std;

int main() {
    srand(time(0));

    cout << "OS is booting up...\n\n";

    // using auth.h
    if (!authenticateUser()) {
        cout << "Authentication failed. Exiting...\n";
        return 1;
    }

    cout << "Login successful. Initializing virtual memory...\n\n";

    int nextFreeFrame = 0;
    int pageSize = 1024;  

    // Run FIFO Scheduling 
    cout << "\nStarting FIFO Scheduling...\n";
    FCFS(nextFreeFrame, pageSize);

    cout << "All processes completed. System shutting down...\n";
    return 0;
}
