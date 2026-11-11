# Simple Makefile for External Game Client

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
INCLUDES = -I/usr/include/lua5.4 -I/usr/include/directx
LIBRARIES = -ld3d11 -ldxgi -llua5.4 -luser32 -lkernel32

# Source files
SRCS = main.cpp \
       ExternalProcessController.cpp \
       LuaVMEnvironment.cpp \
       MemoryAccessLayer.cpp \
       InputSimulationSystem.cpp \
       RenderingEngine.cpp \
       ConfigManager.cpp \
       UIFramework.cpp

# Object files  
OBJS = $(SRCS:.cpp=.o)

# Target executable name
TARGET = external_game_client

# Default target
default: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LIBRARIES)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f *.o $(TARGET)

.PHONY: default clean

# Dependency rules for development (optional)
main.o: main.cpp ExternalProcessController.h MemoryAccessLayer.h InputSimulationSystem.h RenderingEngine.h ConfigManager.h UIFramework.h
ExternalProcessController.o: ExternalProcessController.cpp ExternalProcessController.h LuaVMEnvironment.h MemoryAccessLayer.h InputSimulationSystem.h RenderingEngine.h
LuaVMEnvironment.o: LuaVMEnvironment.cpp LuaVMEnvironment.h
MemoryAccessLayer.o: MemoryAccessLayer.cpp MemoryAccessLayer.h
InputSimulationSystem.o: InputSimulationSystem.cpp InputSimulationSystem.h
RenderingEngine.o: RenderingEngine.cpp RenderingEngine.h
ConfigManager.o: ConfigManager.cpp ConfigManager.h
UIFramework.o: UIFramework.cpp UIFramework.h