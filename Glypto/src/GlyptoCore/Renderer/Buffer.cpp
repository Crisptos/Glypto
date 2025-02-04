#include "GlyptoCore/Logger.h"
#include "GlyptoCore/Renderer/OpenGL/OpenGLBuffer.h"
#include "GlyptoCore/Renderer/Renderer.h"
#include "GlyptoCore/Renderer/Buffer.h"

namespace Glypto
{
    VertexBuffer *VertexBuffer::Create(float *vertices, uint32_t size)
    {
        switch (Renderer::GetRendererBackendAPI())
        {
        case RendererBackendAPI::OPENGL:
        {

            return new OpenGLVertexBuffer(vertices, size);
        }

        default:
        {
            Logger::GLYPTO_CRITICAL("THERE SHOULD BE A GRAPHICS API DEFINED FOR VBOs!");
            return nullptr;
        }
        }
    }

    IndexBuffer *IndexBuffer::Create(uint32_t *indices, uint32_t size)
    {
        switch (Renderer::GetRendererBackendAPI())
        {
        case RendererBackendAPI::OPENGL:
        {

            return new OpenGLIndexBuffer(indices, size);
        }

        default:
        {
            Logger::GLYPTO_CRITICAL("THERE SHOULD BE A GRAPHICS API DEFINED FOR IBOs!");
            return nullptr;
        }
        }
    }
}