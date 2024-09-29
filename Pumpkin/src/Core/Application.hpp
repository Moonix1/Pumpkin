#pragma once

#include "Defines.hpp"

#include "Window.hpp"
#include "Layer/LayerStack.hpp"
#include "Events/Event.hpp"
#include "Events/ApplicationEvent.hpp"

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
        bool m_Running = true;
        LayerStack m_LayerStack;
    private:
        static Application *s_Instance;
    };
    
    Application *CreateApplication();
}