#pragma once

#include "RenderCommand.hpp"

namespace Pumpkin {
    class Renderer {
    public:
        static void BeginScene();
        static void EndScene();

        static void Submit(const std::shared_ptr<VertexArray> &vertexArray);

        static inline RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
    };
}
