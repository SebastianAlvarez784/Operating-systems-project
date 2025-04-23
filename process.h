#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <string>

using namespace std;

enum class ProcessState {
    NEW,
    READY,
    RUNNING,
    WAITING,
    TERMINATED
};

class Process {
private:
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    ProcessState state;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
    int memory_required;
    bool has_io_operations;

public:
    Process(int pid, int arrival, int burst, int prio, int mem, bool io_ops);

    void updateState(ProcessState new_state);
    void executeOneUnit();

    int getPID() const;
    int getArrivalTime() const;
    int getBurstTime() const;
    int getPriority() const;
    ProcessState getState() const;
    int getRemainingTime() const;
    int getWaitingTime() const;
    int getTurnaroundTime() const;
    int getMemoryRequired() const;
    bool hasIO() const;

    void setWaitingTime(int wt);
    void setTurnaroundTime(int tat);

    void printInfo() const;
};

#endif
