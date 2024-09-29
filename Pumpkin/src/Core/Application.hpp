#pragma once

#include "Defines.hpp"
#include "Window.hpp"

#include "../Events/Event.hpp"
#include "../Events/ApplicationEvent.hpp"

namespace Pumpkin {
    class PUMPKIN_API Application {
    public:
        Application();
        virtual ~Application();
        
        void Run();
        
        void OnEvent(Event& event);
    private:
        bool OnWindowClose(WindowCloseEvent &event);
    
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };
    
    Application *CreateApplication();
}