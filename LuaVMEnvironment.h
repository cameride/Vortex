#ifndef LUA_VM_ENVIRONMENT_H
#define LUA_VM_ENVIRONMENT_H

#include <string>

typedef struct {
    float x, y, z;
} Vector3;

struct lua_State;
class LuaVMEnvironment {
public:
    LuaVMEnvironment();
    ~LuaVMEnvironment();
    
    bool ExecuteScript(const std::string& script);
    void ExecuteScriptFile(const std::string& filename);
    
private:
    void InitRobloxAPI();
    lua_State* lua_state;
};

#endif // LUA_VM_ENVIRONMENT_H