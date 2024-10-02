#include "pheader.hpp"
#include "VertexArray.hpp"

#include "Renderer.hpp"
#include "Platform/OpenGL/OpenGLVertexArray.hpp"

namespace Pumpkin {
    VertexArray *VertexArray::Create() {
        switch (Renderer::GetAPI()) {                                                                                   
        case RendererAPI::None: PUMPKIN_CORE_ASSERT(false, "RendererAPI::None is not currently supported!");
        case RendererAPI::OpenGL: return new OpenGLVertexArray();
        }
         
        PUMPKIN_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}
