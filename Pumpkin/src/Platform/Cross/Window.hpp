#pragma once

#include "../../Core/Window.hpp"

#include <GLFW/glfw3.h>

namespace Pumpkin {
    class CWindow : public Window {
    public:
        CWindow(const WindowProps& props);
		virtual ~CWindow();
		
		void OnUpdate() override;
		
		inline unsigned int GetWidth() const override { return m_Data.width; }
		inline unsigned int GetHeight() const override { return m_Data.height; }
		
		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.eventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
    private:
        virtual void Init(const WindowProps &props);
        virtual void Shutdown();
    private:
        GLFWwindow *m_Window;
        
        struct WindowData {
            std::string title;
            unsigned int width, height;
            bool vsync;
            
            EventCallbackFn eventCallback;
        };
        
        WindowData m_Data;
    };
}