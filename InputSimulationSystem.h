#ifndef INPUT_SIMULATION_SYSTEM_H
#define INPUT_SIMULATION_SYSTEM_H

class InputSimulationSystem {
public:
    InputSimulationSystem();
    ~InputSimulationSystem();
    
    void SimulateMouseMove(int x, int y);
    void SimulateMouseClick(int x, int y);
    void SimulateKeyPress(int vk_code);
    void Update();
    
private:
};

#endif // INPUT_SIMULATION_SYSTEM_H