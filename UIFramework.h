#ifndef UI_FRAMEWORK_H
#define UI_FRAMEWORK_H

#include <string>
#include <vector>

class SliderControl;
class ToggleButton;

class UIFramework {
public:
    UIFramework();
    ~UIFramework();
    
    void Initialize();
    void Update();
    void Render();
    
    // Create slider controls with specified ranges and labels
    SliderControl* CreateSlider(const std::string& label, float min, float max, float value);
    ToggleButton* CreateToggleButton(const std::string& label, bool state);
    
private:
    std::vector<SliderControl*> sliders;
    std::vector<ToggleButton*> toggles;
};

// Simple slider control class
class SliderControl {
public:
    SliderControl(const std::string& label, float min, float max, float value);
    void SetValue(float new_value);
    float GetValue() const { return value; }
    std::string GetLabel() const { return label; }
    
private:
    std::string label;
    float min_value;
    float max_value;
    float value;
};

// Simple toggle button class
class ToggleButton {
public:
    ToggleButton(const std::string& label, bool state);
    void SetState(bool new_state);
    bool GetState() const { return state; }
    std::string GetLabel() const { return label; }
    
private:
    std::string label;
    bool state;
};

#endif // UI_FRAMEWORK_H