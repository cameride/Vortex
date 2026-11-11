#ifndef CONFIG_MANAGER_H
#define CONFIG_MANAGER_H

#include <string>
#include <map>
#include <json/json.h> // Using jsoncpp library

class ConfigManager {
public:
    ConfigManager();
    ~ConfigManager();
    
    void LoadSettings(const std::string& filename);
    void SaveSettings(const std::string& filename);
    
    // ESP Settings
    float esp_box_visibility;
    int esp_line_thickness;
    int esp_range_detection;
    float esp_color_intensity;
    
    // Aimbot Settings  
    float aimbot_sensitivity;
    int aimbot_fov_size;
    int aimbot_smoothness_level;
    
    // Movement Controls
    float movement_speed_multiplier;
    int flight_vertical_speed;
    float jump_boost;
    
    // Aim Settings
    int aim_precision_level;
    float aim_reaction_time;

private:
    void LoadDefaultSettings();
    Json::Value config_json;
};

#endif // CONFIG_MANAGER_H