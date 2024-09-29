#include "pheader.hpp"
#include "Input.hpp"

#include "Core/Application.hpp"
#include <GLFW/glfw3.h>

namespace Pumpkin {
    
    Input *Input::s_Instance = new CInput();
    
    bool CInput::IsKeyPressedImpl(int keycode) {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetKey(window, keycode);
        
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }
    
    bool CInput::IsMouseButtonPressedImpl(int button) {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetMouseButton(window, button);
        
        return state == GLFW_PRESS;
    }
    
    std::pair<float, float> CInput::GetMousePositionImpl() {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        
        return { (float)xpos, (float)ypos };
    }
    
    float CInput::GetMouseXImpl() {
        auto[x, y] = GetMousePositionImpl();
        return x;
    }
    
    float CInput::GetMouseYImpl() {
        auto[x, y] = GetMousePositionImpl();
        return y;
    }
    
}