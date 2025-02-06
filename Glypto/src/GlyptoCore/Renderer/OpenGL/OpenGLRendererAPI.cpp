#include "GlyptoCore/Renderer/OpenGL/OpenGLRendererAPI.h"
#include "glad/glad.h"

namespace Glypto
{
    void OpenGLRendererAPI::SetClearColor(glm::vec4& clear_color) const
    {
        glClearColor(
            clear_color.r,
            clear_color.g,
            clear_color.b,
            clear_color.a
        );
    }

    void OpenGLRendererAPI::Clear() const
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void OpenGLRendererAPI::IndexedDraw(const std::shared_ptr<VertexArray>& vao) const
    {
        glDrawElements(
            GL_TRIANGLES,
            vao->GetIndexBuffer()->GetCount(),
            GL_UNSIGNED_INT,
            0
        );
    }
}