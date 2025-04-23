 -Process Class: OS Simulation

This program simulates process management in a basic operating system environment. The `Process` class is used to model the attributes and behaviors of a process in the system.

-Process Class Overview

The Process class contains various attributes that define a process's state, execution time, and resource requirements. It also provides methods for managing the process's lifecycle and state transitions.

-Attributes

- pi` (int):  
  The unique process ID. Every process has a distinct PID.
  
- arrival_time (int):  
  The time at which the process arrives in the system. This is used to simulate the process arrival in the scheduler.
  
- burst_time (int):  
  The total time the process needs the CPU to complete its execution.
  
- priority (int):  
  The priority of the process, used for scheduling decisions. Lower values indicate higher priority.
  
- state (ProcessState):  
  The current state of the process. This can be one of the following:
  - NEW: Process is created but not yet scheduled.
  - READY: Process is ready to run but waiting for the CPU.
  - RUNNING: Process is currently being executed by the CPU.
  - WAITING: Process is waiting for I/O or some other resource.
  - TERMINATED: Process has finished execution.
  
- remaining_time (int):  
  The remaining burst time needed for the process to complete its execution.
  
- waiting_time (int):  
  The total time the process has been waiting in the system (for the CPU or for I/O operations).
  
- turnaround_time (int):  
  The total time from the process's arrival to its completion (i.e., the sum of execution and waiting time).
  
- memory_required(int):  
  The amount of memory required by the process.
  
- has_io_operations (bool):  
  Whether the process has I/O operations. If true, the process will move to a `WAITING` state to simulate I/O activity.



-methods

- Constructor (Process(int pid, int arrival_time, int burst_time, int priority, int memory_required, bool has_io_operations)):  
  Initializes a new process with the specified values for PID, arrival time, burst time, priority, memory required, and whether it requires I/O operations.

- updateState(ProcessState new_state):  
  Updates the state of the process. This allows the process to move through various states like READY, RUNNING, WAITING, and TERMINATED.

- executeOneUnit():  
  Decreases the `remaining_time` of the process by one unit, simulating one unit of CPU execution.

- printInfo():  
  Prints the current details of the process, including PID, arrival time, burst time, remaining time, state, memory required, and I/O operations.

- Getters and Setters:  
  Various getter methods such as getPID(), getRemainingTime(), and setters like setPriority() allow accessing and modifying the attributes of the process.





