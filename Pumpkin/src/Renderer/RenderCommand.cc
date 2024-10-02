#include "pheader.hpp"
#include "RenderCommand.hpp"

#include "Platform/OpenGL/OpenGLRendererAPI.hpp"

namespace Pumpkin {
    RendererAPI *RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}
