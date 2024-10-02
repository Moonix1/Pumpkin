#pragma once

#include "Defines.hpp"

#include "Window.hpp"
#include "Layer/LayerStack.hpp"
#include "Events/Event.hpp"
#include "Events/ApplicationEvent.hpp"

#include "ImGui/ImGuiLayer.hpp"
#include "Renderer/Shader.hpp"
#include "Renderer/Buffer.hpp"
#include "Renderer/VertexArray.hpp"

#include <memory>

namespace Pumpkin {
    class PUMPKIN_API Application {
    public:
        Application();
        virtual ~Application();
        
        void Run();
        
        void OnEvent(Event& event);
        
        void PushLayer(Layer *layer);
        void PushOverlay(Layer *overlay);
        
        inline Window &GetWindow() { return *m_Window; }
        
        inline static Application &Get() { return *s_Instance; }
    private:
        bool OnWindowClose(WindowCloseEvent &event);
    
        std::unique_ptr<Window> m_Window;
        ImGuiLayer *m_ImGuiLayer;
        bool m_Running = true;
        LayerStack m_LayerStack;
        
        std::shared_ptr<Shader> m_TriangleShader;
        std::shared_ptr<VertexArray> m_TriangleVA;
        
        std::shared_ptr<Shader> m_SquareShader;
        std::shared_ptr<VertexArray> m_SquareVA;
    private:
        static Application *s_Instance;
    };
    
    Application *CreateApplication();
}
