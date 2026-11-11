#ifndef EXTERNAL_PROCESS_CONTROLLER_H
#define EXTERNAL_PROCESS_CONTROLLER_H

#include <windows.h>
#include <string>
#include "LuaVMEnvironment.h"
#include "MemoryAccessLayer.h"
#include "InputSimulationSystem.h"
#include "RenderingEngine.h"

class ExternalProcessController {
public:
    ExternalProcessController();
    ~ExternalProcessController();
    
    void Update();
    bool AttachToProcess(const std::string& process_name);
    bool IsAttached() const { return attached_process != NULL; }
    
private:
    HANDLE attached_process;
    DWORD process_id;
    std::string target_process_name;
    
    LuaVMEnvironment* lua_vm_env;
    MemoryAccessLayer* memory_layer;
    InputSimulationSystem* input_system;
    RenderingEngine* rendering_engine;
};

#endif // EXTERNAL_PROCESS_CONTROLLER_H