#pragma once

#include "Renderer/RenderingContext.hpp"

struct GLFWwindow;

namespace Pumpkin {
    class OpenGLContext : public RenderingContext {
    public:
        OpenGLContext(GLFWwindow *windowHandle);
        
        virtual void Init() override;
        virtual void SwapBuffers() override;
    private:
        GLFWwindow *m_WindowHandle;
    };
}