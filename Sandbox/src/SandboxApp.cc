#include "Pumpkin/Pumpkin.hpp"

#include "imgui/imgui.h"

class ExampleLayer : public Pumpkin::Layer {
public:
    ExampleLayer()
        : Layer("Example") {}
        
    void OnUpdate() override {
        
    }
    
    virtual void OnImGuiRender() override {
        ImGui::Begin("Test");
        ImGui::Text("Hello, Pumpkin!");
        ImGui::End();
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
    }
    
    ~Sandbox() {
        
    }
};

Pumpkin::Application *Pumpkin::CreateApplication() {
    return new Sandbox();
}