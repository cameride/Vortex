# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(ExternalGameClient)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories  
include_directories(${CMAKE_SOURCE_DIR})

# Source files
set(SOURCES
    main.cpp
    ExternalProcessController.cpp
    LuaVMEnvironment.cpp
    MemoryAccessLayer.cpp
    InputSimulationSystem.cpp
    RenderingEngine.cpp
    ConfigManager.cpp
    UIFramework.cpp
)

# Header files (for IDE support)
set(HEADERS
    ExternalProcessController.h
    LuaVMEnvironment.h
    MemoryAccessLayer.h
    InputSimulationSystem.h
    RenderingEngine.h
    ConfigManager.h
    UIFramework.h
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Link libraries (Windows-specific)
target_link_libraries(${PROJECT_NAME} 
    user32
    kernel32
    d3d11
    dxgi
    lua54  # assuming Lua 5.4 library
)

# Set properties for Windows GUI applications if needed
target_compile_definitions(${PROJECT_NAME} PRIVATE WIN32_LEAN_AND_MEAN)