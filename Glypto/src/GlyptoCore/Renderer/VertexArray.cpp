#include "GlyptoCore/Renderer/VertexArray.h"
#include "GlyptoCore/Renderer/OpenGL/OpenGLVertexArray.h"

namespace Glypto
{
    VertexArray *VertexArray::Create()
    {
        switch (Renderer::GetRendererBackendAPI())
        {
        case RendererBackendAPI::OPENGL:
        {

            return new OpenGLVertexArray();
        }

        default:
        {
            Logger::GLYPTO_CRITICAL("THERE SHOULD BE A GRAPHICS API DEFINED FOR VBOs!");
            return nullptr;
        }
        }
    }
}