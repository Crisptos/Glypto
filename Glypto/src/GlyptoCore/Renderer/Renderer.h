#pragma once
#include <stdint.h>
#include "GlyptoCore/Renderer/RenderCommand.h"
#include "GlyptoCore/Renderer/OrthoCamera.h"
#include "GlyptoCore/Renderer/Shader.h"

namespace Glypto
{
    class Renderer
    {
    public:
        static RendererAPI::Backend GetRendererAPIBackend();

        static void BeginScene();
        static void EndScene();

        // TODO - Proper scene data
        static void SubmitScene(const std::shared_ptr<VertexArray> &vao, const Shader &shader, OrthoCamera& camera);
    };
}