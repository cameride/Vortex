#ifndef RENDERING_ENGINE_H
#define RENDERING_ENGINE_H

class RenderingEngine {
public:
    RenderingEngine();
    ~RenderingEngine();
    
    void InitializeOverlay();
    void RenderESP();
    void RenderUI();
    void Update();
    
private:
};

#endif // RENDERING_ENGINE_H