#ifndef VIRTUALMEMORY_H
#define VIRTUALMEMORY_H

#include <vector>
#include <unordered_map>

struct PageTableEntry {
    int page_number;  // Virtual page number
    int frame_number;  // Physical frame number
    bool valid_bit;  // Indicates if the page is in memory
    bool dirty_bit;  // Tracks modified pages (if implementing write-back)
};

class VirtualMemory {
private:
    int virtual_memory_size;
    int physical_memory_size;
    int page_size;
    std::vector<int> physical_memory;  // Simulated physical memory frames
    std::unordered_map<int, std::vector<PageTableEntry>> page_tables;  // Process page tables

public:
    // Constructor
    VirtualMemory(int virtual_size, int physical_size, int page_sz);

    // Memory management methods
    void allocatePageTable(int pid);
    int translateAddress(int pid, int virtual_address);
    void handlePageFault(int pid, int page_number);
};

#endif // VIRTUALMEMORY_H
