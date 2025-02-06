#pragma once
#include <stdint.h>
#include "GlyptoCore/Renderer/RenderCommand.h"

namespace Glypto
{

    class Renderer
    {
    public:
        static RendererAPI::Backend GetRendererAPIBackend();

        static void BeginScene();
        static void EndScene();
        static void SubmitScene(const std::shared_ptr<VertexArray> &vao);
    };
}