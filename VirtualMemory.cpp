#include "VirtualMemory.h"
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

// FIFO queue to track pages currently in memory
queue<int> pageQueue;

// Constructor: Initializes memory parameters
VirtualMemory::VirtualMemory(int virtual_size, int physical_size, int page_sz)
    : virtual_memory_size(virtual_size), physical_memory_size(physical_size), page_size(page_sz) {
    int num_frames = physical_memory_size / page_size;
    physical_memory.resize(num_frames, -1);  

    cout << " Virtual Memory initialized: " << virtual_memory_size << " bytes\n";
}

// Method to allocate a page table for a process
void VirtualMemory::allocatePageTable(int pid) {
    int max_pages = virtual_memory_size / page_size;  
    cout << " Allocating page table for Process " << pid << " (Max pages: " << max_pages << ")\n";

    page_tables[pid] = vector<PageTableEntry>();
}

// Method to translate a virtual address to a physical address
int VirtualMemory::translateAddress(int pid, int virtual_address) {
    if (virtual_address >= virtual_memory_size) {
        cerr << " Error: Virtual address exceeds allocated virtual memory!\n";
        return -1;
    }

    int page_number = virtual_address / page_size;
    int offset = virtual_address % page_size;

    if (page_tables.find(pid) == page_tables.end()) {
        cerr << " Error: Process page table not found.\n";
        return -1;
    }

    for (auto &entry : page_tables[pid]) {
        if (entry.page_number == page_number && entry.valid_bit) {
            return (entry.frame_number * page_size) + offset;  
        }
    }

    handlePageFault(pid, page_number);
    return -1;
}

// Method to handle page faults using FIFO replacement
void VirtualMemory::handlePageFault(int pid, int page_number) {
    cout << " Page Fault! Process " << pid << " requested page " << page_number << ".\n";

    int num_frames = physical_memory.size();
    int free_frame = -1;

    for (int i = 0; i < num_frames; i++) {
        if (physical_memory[i] == -1) {  
            free_frame = i;
            break;
        }
    }

    if (free_frame != -1) {  
        physical_memory[free_frame] = pid;
        PageTableEntry new_entry = {page_number, free_frame, true, false};
        page_tables[pid].push_back(new_entry);

        pageQueue.push(page_number);  

        cout << " Page " << page_number << " loaded into Frame " << free_frame << " for Process " << pid << ".\n";

    } else {  
        int evicted_page = pageQueue.front();
        pageQueue.pop();

        cout << " Evicting Page " << evicted_page << " to free memory.\n";

        // Find and reuse the evicted page’s frame
        for (auto &entry : page_tables[pid]) {
            if (entry.page_number == evicted_page) {
                free_frame = entry.frame_number;  // Assign freed frame
                entry.valid_bit = false;  
                break;
            }
        }

        physical_memory[free_frame] = pid;
        PageTableEntry new_entry = {page_number, free_frame, true, false};
        page_tables[pid].push_back(new_entry);
        pageQueue.push(page_number);  

        cout << " Page " << page_number << " replaced into Frame " << free_frame << " for Process " << pid << ".\n";
    }
}
