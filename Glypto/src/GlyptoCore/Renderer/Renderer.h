#pragma once
#include <stdint.h>
#include "GlyptoCore/Renderer/Buffer.h"

namespace Glypto
{
    enum class RendererBackendAPI : uint8_t
    {
        NONE = 0,
        OPENGL
    };

    class Renderer
    {
    public:
        static RendererBackendAPI GetRendererBackendAPI() { return s_RendererBackendAPI; }
        

    private:
        static RendererBackendAPI s_RendererBackendAPI;
    };
}