#include "Application.hpp"
#include "Defines.hpp"

#include <GL/gl.h>
#include <GLFW/glfw3.h>

namespace Pumpkin {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
    
    Application *Application::s_Instance = nullptr;

    Application::Application() {
        PUMPKIN_CORE_ASSERT(s_Instance, "Application already exists!");
        s_Instance = this;
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
    }
    
    Application::~Application() {
        
    }
    
    void Application::OnEvent(Event& event) {
        EventDispatcher dispatcher(event);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
        
        for (auto it = m_LayerStack.end() ; it != m_LayerStack.begin();) {
            (*--it)->OnEvent(event);
            if (event.handled)
                break;
        }
        
        PUMPKIN_CORE_INFO("{0}", event.ToString());
    }
    
    void Application::PushLayer(Layer *layer) {
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }
    
    void Application::PushOverlay(Layer *overlay) {
        m_LayerStack.PushOverlay(overlay);
        overlay->OnAttach();
    }
    
    bool Application::OnWindowClose(WindowCloseEvent &event) {
        m_Running = false;
        return true;
    }
    
    void Application::Run() {
        while (m_Running) {
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            
            for (Layer *layer : m_LayerStack)
                layer->OnUpdate();
            
            m_Window->OnUpdate();
        }
    }
}