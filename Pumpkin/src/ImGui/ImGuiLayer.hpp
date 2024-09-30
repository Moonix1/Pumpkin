#pragma once

#include "Core/Defines.hpp"
#include "Layer/Layer.hpp"

#include "Events/ApplicationEvent.hpp"
#include "Events/KeyEvent.hpp"
#include "Events/MouseEvent.hpp"

namespace Pumpkin {
    class PUMPKIN_API ImGuiLayer : public Layer {
    public:
        ImGuiLayer();
        ~ImGuiLayer();
        
        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnImGuiRender() override;
        
        void Begin();
        void End();
    private:
        float m_Time = 0.0f;
    };
}