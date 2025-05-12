#include "Process.h"
#include <iostream>

// Constructor: Initialize process attributes
Process::Process(int id, int arrival, int burst, int priority, int memory, bool io_flag)
    : pid(id),
      arrival_time(arrival), 
      burst_time(burst),
      remaining_time(burst),
      waiting_time(0),
      turnaround_time(0),
      memory_required(memory),
      priority(priority),
      state("NEW"),
      has_io_operations(io_flag) {}

// Method to update process state
void Process::setState(std::string new_state) {
    state = new_state;
}

// Method to decrement remaining execution time
void Process::decrementExecutionTime() {
    if (remaining_time > 0) {
        remaining_time--;
    }
}

// Method to update turnaround time
void Process::updateTurnaroundTime(int current_time) {
    turnaround_time = current_time - arrival_time;
}

// Method to update waiting time
void Process::updateWaitingTime(int queue_time) {
    waiting_time += queue_time;
}

// Getters
int Process::getPID() const { return pid; }
int Process::getArrivalTime() const { return arrival_time; }
int Process::getBurstTime() const { return burst_time; }
int Process::getPriority() const { return priority; }
int Process::getRemainingTime() const { return remaining_time; }
int Process::getWaitingTime() const { return waiting_time; }
int Process::getTurnaroundTime() const { return turnaround_time; }
int Process::getMemoryRequired() const { return memory_required; }
bool Process::hasIOOperations() const { return has_io_operations; }
std::string Process::getState() const { return state; }

// Setters
void Process::setPriority(int new_priority) { priority = new_priority; }
void Process::setMemoryRequired(int new_memory) { memory_required = new_memory; }
