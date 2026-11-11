#include "ConfigManager.h"
#include <fstream>
#include <iostream>

ConfigManager::ConfigManager() {
    LoadDefaultSettings();
}

ConfigManager::~ConfigManager() {
    // Cleanup if needed
}

void ConfigManager::LoadDefaultSettings() {
    // ESP Settings
    esp_box_visibility = 1.0f;
    esp_line_thickness = 2;
    esp_range_detection = 200;
    esp_color_intensity = 0.8f;
    
    // Aimbot Settings  
    aimbot_sensitivity = 1.0f;
    aimbot_fov_size = 90;
    aimbot_smoothness_level = 5;
    
    // Movement Controls
    movement_speed_multiplier = 2.0f;
    flight_vertical_speed = 10;
    jump_boost = 2.0f;
    
    // Aim Settings
    aim_precision_level = 7;
    aim_reaction_time = 0.2f;
}

void ConfigManager::LoadSettings(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open config file: " << filename << std::endl;
        LoadDefaultSettings();
        return;
    }
    
    try {
        Json::Reader reader;
        reader.parse(file, config_json);
        
        // Parse ESP settings
        esp_box_visibility = config_json.get("esp.box_visibility", 1.0f).asFloat();
        esp_line_thickness = config_json.get("esp.line_thickness", 2).asInt();
        esp_range_detection = config_json.get("esp.range_detection", 200).asInt();
        esp_color_intensity = config_json.get("esp.color_intensity", 0.8f).asFloat();
        
        // Parse Aimbot settings
        aimbot_sensitivity = config_json.get("aimbot.sensitivity", 1.0f).asFloat();
        aimbot_fov_size = config_json.get("aimbot.fov_size", 90).asInt();
        aimbot_smoothness_level = config_json.get("aimbot.smoothness_level", 5).asInt();
        
        // Parse Movement controls
        movement_speed_multiplier = config_json.get("movement.speed_multiplier", 2.0f).asFloat();
        flight_vertical_speed = config_json.get("movement.flight_vertical_speed", 10).asInt();
        jump_boost = config_json.get("movement.jump_boost", 2.0f).asFloat();
        
        // Parse Aim settings
        aim_precision_level = config_json.get("aim.precision_level", 7).asInt();
        aim_reaction_time = config_json.get("aim.reaction_time", 0.2f).asFloat();
    }
    catch (const std::exception& e) {
        std::cerr << "Error parsing config file: " << e.what() << std::endl;
        LoadDefaultSettings();
    }
}

void ConfigManager::SaveSettings(const std::string& filename) {
    // Prepare configuration data
    Json::Value root(Json::objectValue);
    
    // ESP Settings
    root["esp"]["box_visibility"] = esp_box_visibility;
    root["esp"]["line_thickness"] = esp_line_thickness;
    root["esp"]["range_detection"] = esp_range_detection;
    root["esp"]["color_intensity"] = esp_color_intensity;
    
    // Aimbot Settings  
    root["aimbot"]["sensitivity"] = aimbot_sensitivity;
    root["aimbot"]["fov_size"] = aimbot_fov_size;
    root["aimbot"]["smoothness_level"] = aimbot_smoothness_level;
    
    // Movement Controls
    root["movement"]["speed_multiplier"] = movement_speed_multiplier;
    root["movement"]["flight_vertical_speed"] = flight_vertical_speed;
    root["movement"]["jump_boost"] = jump_boost;
    
    // Aim Settings
    root["aim"]["precision_level"] = aim_precision_level;
    root["aim"]["reaction_time"] = aim_reaction_time;
    
    // Save to file
    std::ofstream file(filename);
    if (file.is_open()) {
        Json::StreamWriterBuilder builder;
        builder["indentation"] = "  ";
        Json::writeString(builder, root, &file);
        file.close();
        std::cout << "Settings saved successfully." << std::endl;
    } else {
        std::cerr << "Could not save config file: " << filename << std::endl;
    }
}