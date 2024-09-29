#include "Application.hpp"

#include <GL/gl.h>
#include <GLFW/glfw3.h>

namespace Pumpkin {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
    
    Application::Application() {
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
    }
    
    Application::~Application() {
        
    }
    
    void Application::OnEvent(Event& event) {
        EventDispatcher dispatcher(event);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
        
        PUMPKIN_CORE_INFO("{0}", event.ToString());
    }
    
    bool Application::OnWindowClose(WindowCloseEvent &event) {
        m_Running = false;
        return true;
    }
    
    void Application::Run() {
        while (m_Running) {
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            m_Window->OnUpdate();
        }
    }
}