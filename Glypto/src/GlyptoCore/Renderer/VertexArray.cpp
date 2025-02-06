#include "GlyptoCore/Renderer/VertexArray.h"
#include "GlyptoCore/Renderer/Renderer.h"
#include "GlyptoCore/Renderer/OpenGL/OpenGLVertexArray.h"
#include "GlyptoCore/Logger.h"

namespace Glypto
{
    VertexArray *VertexArray::Create()
    {
        switch (Renderer::GetRendererAPIBackend())
        {
        case RendererAPI::Backend::OPENGL:
        {

            return new OpenGLVertexArray();
        }

        default:
        {
            Logger::GLYPTO_CRITICAL("THERE SHOULD BE A GRAPHICS API DEFINED FOR VAOs!");
            return nullptr;
        }
        }
    }
}