#include "RendererAPI.h"

namespace Glypto
{
    // Hardcoded OPENGL backend
    RendererAPI::Backend RendererAPI::s_Backend = RendererAPI::Backend::OPENGL;

    RendererAPI::Backend RendererAPI::GetBackend()
    {
        return s_Backend;
    }
}