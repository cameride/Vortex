#include "MemoryAccessLayer.h"
#include <windows.h>
#include <iostream>

MemoryAccessLayer::MemoryAccessLayer() {
    process_handle = NULL;
    std::cout << "Memory Access Layer initialized." << std::endl;
}

MemoryAccessLayer::~MemoryAccessLayer() {
    if (process_handle != NULL) {
        CloseHandle(process_handle);
    }
}

bool MemoryAccessLayer::AttachToProcess(DWORD pid) {
    process_handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (process_handle == NULL) {
        std::cerr << "Failed to open process: " << GetLastError() << std::endl;
        return false;
    }
    
    process_id = pid;
    std::cout << "Successfully attached to process ID: " << pid << std::endl;
    return true;
}

bool MemoryAccessLayer::ReadMemory(void* address, void* buffer, size_t size) {
    if (process_handle == NULL || address == NULL || buffer == NULL) {
        return false;
    }
    
    SIZE_T bytes_read = 0;
    bool success = ReadProcessMemory(process_handle, address, buffer, size, &bytes_read);
    
    if (!success) {
        std::cerr << "Failed to read memory at address: " << address 
                  << ", Error code: " << GetLastError() << std::endl;
        return false;
    }
    
    return true;
}

bool MemoryAccessLayer::WriteMemory(void* address, const void* buffer, size_t size) {
    if (process_handle == NULL || address == NULL || buffer == NULL) {
        return false;
    }
    
    SIZE_T bytes_written = 0;
    bool success = WriteProcessMemory(process_handle, address, buffer, size, &bytes_written);
    
    if (!success) {
        std::cerr << "Failed to write memory at address: " << address 
                  << ", Error code: " << GetLastError() << std::endl;
        return false;
    }
    
    return true;
}

void MemoryAccessLayer::Update() {
    // This method will be called periodically in the main loop
    // Could contain periodic memory scanning or updates if needed
}