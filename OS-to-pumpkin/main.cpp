#include <iostream>
#include <thread>
#include <chrono>
#include <stdlib.h>
// 4 KB; page size in bytes
const uint64_t PAGE_SIZE = 4 * 1024; 
// 8 GB; size of memory to allocate in bytes divided by 1024
const uint64_t MEM_SIZE = 8 * 1024 * 1024;
 
const std::size_t delay_ms = 60;

volatile int global_data;

void access_memory(char* ptr, int mode) {
    for (std::size_t i = 0; i < MEM_SIZE / (PAGE_SIZE / 1024); ++i) {

        // access memory
        if (mode == 1){
            // mode 1: read
            global_data = *reinterpret_cast<int*>(ptr + i * PAGE_SIZE);
        } else {
            // mode 2: write
            ptr[i * PAGE_SIZE] = 0;
        }

        // print page number and delay 
        if (i % 5000 == 0) {
            std::cout << "\nCurrent page number: " << i;
            std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
        }
    }

    std::cout << "\nPages ended\n";
}

int main() {
    char* memory;
    
    std::cout << "Enter '1' or '2' to choose read or write mode: ";
    int choice;
    std::cin >> choice;
    std::cout << std::endl;
    if (choice != 1 and choice != 2){
        std::cout << "\nError: unknown mode\n";
        return 1;
    }

    try {
        // allocate memory block in bytes
        memory = new char[MEM_SIZE * 1024]; 
    } catch (const std::bad_alloc &e) {
        std::cerr << "\nError allocating memory: " << e.what() << std::endl;
    }
    
    std::cout << "\nMemory is allocated";
    access_memory(memory, choice);
    
    delete[] memory;
    return 0;
}