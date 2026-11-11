# Advanced External Game Client

This is an advanced external game client designed with extensive features including ESP (Enhanced Spectator Mode), aimbot, movement controls, and adjustable settings. The system implements a modular architecture that handles process interaction, memory management, input simulation, and visual overlays.

## Project Structure
```
client_core/
├── main.cpp                   # Main application entry point
├── CMakeLists.txt            # CMake build configuration  
├── Makefile                  # Unix/Linux makefile for builds
├── build.bat                 # Windows batch script for building
├── config.json               # Configuration file with all settings
│
├── ExternalProcessController.h/.cpp  # Core system coordination
├── LuaVMEnvironment.h/.cpp           # Script execution engine  
├── MemoryAccessLayer.h/.cpp          # Memory reading/writing functions
├── InputSimulationSystem.h/.cpp      # Mouse/keyboard input simulation
├── RenderingEngine.h/.cpp            # Overlay rendering components
├── ConfigManager.h/.cpp              # Configuration management
└── UIFramework.h/.cpp                # User interface controls
```

## Core Architecture

### System Components:

1. **External Process Controller**
   - Manages process attachment to target applications  
   - Coordinates all system subsystems
   - Handles lifecycle management of attached processes

2. **LuaVM Environment** 
   - Lua 5.4 interpreter engine for script execution
   - Roblox API emulation layer for compatibility
   - Script execution context with security measures

3. **Memory Access Layer**
   - Windows API-based memory reading/writing functions  
   - Process attachment system for secure access  
   - Error handling and validation for safety

4. **Input Simulation System** 
   - Mouse control module with absolute positioning
   - Keyboard input handler for key presses
   - Hardware abstraction for cross-platform compatibility

5. **Rendering Engine**
   - DirectX/OpenGL overlay interface
   - UI framework with interactive sliders  
   - Real-time drawing components for ESP and controls

## Key Features Implementation

### ESP System:
- Player detection through memory reading
- Visual indicators (bounding boxes, name tags)
- Color coding for teammates/enemies
- Adjustable settings: box size, line thickness, range, color intensity

### Aimbot Module:
- Target tracking with algorithmic approach
- Smooth movement using interpolation  
- Adjustable sensitivity, FOV, smoothness levels

### Movement Controls:
- No-clip feature with physics override
- Flight mode for gravity manipulation
- Speed multiplier and collision toggle settings

## Technical Requirements

### System Components:
**Windows Development Environment:**
- C++/C# Framework (Visual Studio 2022+)
- DirectX 11/12 Libraries for Overlay Rendering  
- Windows API Access for Process Control
- Lua 5.4 Engine Integration
- Memory Reading/Writing Permissions

**Communication Protocols:**
- HTTP Bridge Communication 
- WebSocket Support (for MCP integration)  
- Local Socket Interface

### Security Considerations:
- Anti-Detection Techniques  
- Process Injection Prevention Methods
- Signature Avoidance for Hook Detection