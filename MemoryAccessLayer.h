#ifndef MEMORY_ACCESS_LAYER_H
#define MEMORY_ACCESS_LAYER_H

#include <windows.h>
#include <string>

class MemoryAccessLayer {
public:
    MemoryAccessLayer();
    ~MemoryAccessLayer();
    
    bool AttachToProcess(DWORD pid);
    bool ReadMemory(void* address, void* buffer, size_t size);
    bool WriteMemory(void* address, const void* buffer, size_t size);
    void Update();
    
private:
    HANDLE process_handle;
    DWORD process_id;
};

#endif // MEMORY_ACCESS_LAYER_H