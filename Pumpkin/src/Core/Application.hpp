#pragma once

#include "Defines.hpp"

namespace Pumpkin {
    class PUMPKIN_API Application {
    public:
        Application();
        virtual ~Application();
        
        void Run();
    };
    
    Application *CreateApplication();
}