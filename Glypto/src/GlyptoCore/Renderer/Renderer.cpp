#include "GlyptoCore/Renderer/Renderer.h"

namespace Glypto
{
    void Renderer::BeginScene()
    {
        glm::vec4 clear_color(0.23f, 0.2f, 0.23f, 1.0f);
        RenderCommand::SetClearColor(clear_color);
    }

    void Renderer::EndScene()
    {
    }

    void Renderer::SubmitScene(const std::shared_ptr<VertexArray> &vao)
    {
        RenderCommand::Clear();
        RenderCommand::IndexedDraw(vao);
    }

    RendererAPI::Backend Renderer::GetRendererAPIBackend()
    {
        return RendererAPI::GetBackend();
    }
}