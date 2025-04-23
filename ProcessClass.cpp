#include "process.h"  // Include the header file to link the class declaration with the definition

// Constructor definition
Process::Process(int pid, int arrival, int burst, int prio, int mem, bool io_ops)
    : pid(pid), arrival_time(arrival), burst_time(burst), priority(prio), state(ProcessState::NEW),
      remaining_time(burst), waiting_time(0), turnaround_time(0), memory_required(mem), has_io_operations(io_ops) {}

// Method to update the state
void Process::updateState(ProcessState new_state) {
    state = new_state;
}

// Method to decrement remaining execution time
void Process::executeOneUnit() {
    if (remaining_time > 0) {
        remaining_time--;
    }
}

// Getter methods
int Process::getPID() const { return pid; }
int Process::getArrivalTime() const { return arrival_time; }
int Process::getBurstTime() const { return burst_time; }
int Process::getPriority() const { return priority; }
ProcessState Process::getState() const { return state; }
int Process::getRemainingTime() const { return remaining_time; }
int Process::getWaitingTime() const { return waiting_time; }
int Process::getTurnaroundTime() const { return turnaround_time; }
int Process::getMemoryRequired() const { return memory_required; }
bool Process::hasIO() const { return has_io_operations; }

// Setter methods
void Process::setWaitingTime(int wt) { waiting_time = wt; }
void Process::setTurnaroundTime(int tat) { turnaround_time = tat; }

// Print process info
void Process::printInfo() const {
    std::cout << "PID: " << pid
              << ", Arrival: " << arrival_time
              << ", Burst: " << burst_time
              << ", Priority: " << priority
              << ", Remaining: " << remaining_time
              << ", State: " << static_cast<int>(state)
              << ", Waiting: " << waiting_time
              << ", Turnaround: " << turnaround_time
              << ", Memory: " << memory_required
              << ", IO: " << (has_io_operations ? "Yes" : "No")
              << std::endl;
}
