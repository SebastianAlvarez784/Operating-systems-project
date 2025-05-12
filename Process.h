#ifndef PROCESS_H
#define PROCESS_H

#include <string>

class Process {
private:
    // Process attributes
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
    int memory_required;
    int priority;
    std::string state;
    bool has_io_operations;

public:
    // Constructor
    Process(int id, int arrival, int burst, int priority, int memory, bool io_flag);

    // Methods to manipulate process state and execution
    void setState(std::string new_state);
    void decrementExecutionTime();
    void updateTurnaroundTime(int current_time);
    void updateWaitingTime(int queue_time);

    // Getters
    int getPID() const;
    int getArrivalTime() const;
    int getBurstTime() const;
    int getPriority() const;
    int getRemainingTime() const;
    int getWaitingTime() const;
    int getTurnaroundTime() const;
    int getMemoryRequired() const;
    bool hasIOOperations() const;
    std::string getState() const;

    // Setters
    void setPriority(int new_priority);
    void setMemoryRequired(int new_memory);
};

#endif // PROCESS_H
