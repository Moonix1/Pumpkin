#pragma once

#include "Core/Defines.hpp"
#include "Layer/Layer.hpp"

namespace Pumpkin {
    class PUMPKIN_API ImGuiLayer : public Layer {
    public:
        ImGuiLayer();
        ~ImGuiLayer();
        
        void OnAttach();
        void OnDetach();
        void OnUpdate();
        void OnEvent(Event &event);
    private:
        float m_Time = 0.0f;
    };
}