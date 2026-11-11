#include "LuaVMEnvironment.h"
#include <lua.hpp>
#include <iostream>

LuaVMEnvironment::LuaVMEnvironment() {
    lua_state = luaL_newstate();
    if (lua_state != NULL) {
        // Load standard libraries
        luaL_openlibs(lua_state);
        
        // Initialize Roblox API emulation layer
        InitRobloxAPI();
        
        std::cout << "LuaVM Environment initialized successfully." << std::endl;
    } else {
        std::cerr << "Failed to initialize LuaVM environment!" << std::endl;
    }
}

LuaVMEnvironment::~LuaVMEnvironment() {
    if (lua_state != NULL) {
        lua_close(lua_state);
    }
}

void LuaVMEnvironment::InitRobloxAPI() {
    // Register Roblox API functions
    // This is a placeholder for the actual Roblox API emulation layer
    std::cout << "Initializing Roblox API Emulation Layer..." << std::endl;
}

bool LuaVMEnvironment::ExecuteScript(const std::string& script) {
    if (lua_state == NULL) return false;
    
    int result = luaL_dostring(lua_state, script.c_str());
    
    if (result != LUA_OK) {
        const char* error = lua_tostring(lua_state, -1);
        std::cerr << "Lua Error: " << error << std::endl;
        lua_pop(lua_state, 1);
        return false;
    }
    
    return true;
}

void LuaVMEnvironment::ExecuteScriptFile(const std::string& filename) {
    if (lua_state == NULL) return;
    
    int result = luaL_dofile(lua_state, filename.c_str());
    
    if (result != LUA_OK) {
        const char* error = lua_tostring(lua_state, -1);
        std::cerr << "Lua File Error: " << error << std::endl;
        lua_pop(lua_state, 1);
    }
}