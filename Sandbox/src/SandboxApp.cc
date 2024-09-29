#include "Pumpkin/Pumpkin.hpp"

class ExampleLayer : public Pumpkin::Layer {
public:
    ExampleLayer()
        : Layer("Example") {}
        
    void OnUpdate() override {
        PUMPKIN_INFO("ExampleLayer::Update");
    }
    
    void OnEvent(Pumpkin::Event &event) override {
        PUMPKIN_INFO("{0}", event.ToString());
    }
};

class Sandbox : public Pumpkin::Application {
public:
    Sandbox() {
        PushLayer(new ExampleLayer);
    }
    
    ~Sandbox() {
        
    }
};

Pumpkin::Application *Pumpkin::CreateApplication() {
    return new Sandbox();
}