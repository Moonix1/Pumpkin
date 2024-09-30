#pragma once

namespace Pumpkin {
    class RenderingContext {
    public:
        virtual void Init() = 0;
        virtual void SwapBuffers() = 0;
    };
}