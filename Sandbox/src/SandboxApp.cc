#include "Pumpkin/Pumpkin.hpp"

class ExampleLayer : public Pumpkin::Layer {
public:
    ExampleLayer()
        : Layer("Example") {}
        
    void OnUpdate() override {
        
    }
    
    void OnEvent(Pumpkin::Event &event) override {
        if (event.GetEventType() == Pumpkin::EventType::KeyPressed) {
            Pumpkin::KeyPressedEvent &e = (Pumpkin::KeyPressedEvent&)event;
            PUMPKIN_TRACE("Key pressed: {0}", (char)e.GetKeyCode());
        }
    }
};

class Sandbox : public Pumpkin::Application {
public:
    Sandbox() {
        PushLayer(new ExampleLayer());
        PushOverlay(new Pumpkin::ImGuiLayer());
    }
    
    ~Sandbox() {
        
    }
};

Pumpkin::Application *Pumpkin::CreateApplication() {
    return new Sandbox();
}