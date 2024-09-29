#include "Window.hpp"

namespace Pumpkin {
    static bool s_GLFWInitialized = false;
    
    Window *Window::Create(const WindowProps &props) {
        return new CWindow(props);
    }
    
    CWindow::CWindow(const WindowProps &props) {
        Init(props);
    }
    
    CWindow::~CWindow() {
        
    }
    
    Window::~Window() {
        
    }
    
    void CWindow::Init(const WindowProps &props) {
        m_Data.title = props.title;
        m_Data.width = props.width;
        m_Data.height = props.height;
        
        PUMPKIN_CORE_INFO("Creating window {0} ({1}, {2})", props.title, props.width, props.height);
        
        if (!s_GLFWInitialized) {
            int success = glfwInit();
            PUMPKIN_CORE_ASSERT(success, "Could not initialize GLFW!");
            
            s_GLFWInitialized = true;
        }
        
        m_Window = glfwCreateWindow((int)props.width, (int)props.height,
                                    m_Data.title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);
    }
    
    void CWindow::Shutdown() {
        glfwDestroyWindow(m_Window);
    }
    
    void CWindow::OnUpdate() {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }
    
    void CWindow::SetVSync(bool enabled) {
        if (enabled) {
            glfwSwapInterval(1);
        } else {
            glfwSwapInterval(0);
        }
        
        m_Data.vsync = enabled;
    }
    
    bool CWindow::IsVSync() const {
        return m_Data.vsync;
    }
}