#include "pheader.hpp"
#include "Buffer.hpp"

#include "Renderer.hpp"

#include "Platform/OpenGL/OpenGLBuffer.hpp"

namespace Pumpkin {
    VertexBuffer *VertexBuffer::Create(float *vertices, size_t size) {
        switch (Renderer::GetAPI()) {
            case RendererAPI::None: PUMPKIN_CORE_ASSERT(false, "RendererAPI::None is not currently supported!");
            case RendererAPI::OpenGL: return new OpenGLVertexBuffer(vertices, size);
        }
        
        PUMPKIN_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
    
    IndexBuffer *IndexBuffer::Create(uint32_t *indices, size_t size) {
        switch (Renderer::GetAPI()) {
            case RendererAPI::None: PUMPKIN_CORE_ASSERT(false, "RendererAPI::None is not currently supported!");
            case RendererAPI::OpenGL: return new OpenGLIndexBuffer(indices, size);
        }
        
        PUMPKIN_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}