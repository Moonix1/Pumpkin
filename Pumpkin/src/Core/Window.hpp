#pragma once

#include "pheader.hpp"
#include "Defines.hpp"
#include "Events/Event.hpp"

namespace Pumpkin {
    struct WindowProps {
        std::string title;
        unsigned int width;
        unsigned int height;
        
        WindowProps(const std::string &title = "Pumpkin Engine",
                    unsigned int width = 800,
                    unsigned int height = 620)
            : title(title), width(width), height(height) {}
    };
    
    class PUMPKIN_API Window {
    public:
        using EventCallbackFn = std::function<void(Event&)>;
        
        virtual ~Window();
        
        virtual void OnUpdate() = 0;
        
        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;
        
        virtual void SetEventCallback(const EventCallbackFn &callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;
        
        static Window *Create(const WindowProps &props = WindowProps());
    };
}