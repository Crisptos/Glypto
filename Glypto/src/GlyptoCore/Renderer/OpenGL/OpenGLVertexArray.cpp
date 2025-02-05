#include "GlyptoCore/Renderer/OpenGL/OpenGLVertexArray.h"

namespace Glypto
{
    void OpenGLVertexArray::Bind() const
    {
        glBindVertexArray(m_RendererID);
    }

    void OpenGLVertexArray::Unbind() const
    {
        glBindVertexArray(0);
    }

    void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer> &vbo)
    {
        glBindVertexArray(m_RendererID);
        vbo->Bind();

        const BufferLayout &vbo_layout = vbo->GetLayout();
        int location = 0;
        for (const BufferElement &element : vbo_layout.GetElements())
        {
            glEnableVertexAttribArray(location);
            glVertexAttribPointer(
                location,
                CountOfShaderDataType(element.data_type),
                GL_FLOAT,
                element.normalized,
                element.size,
                (const void *)element.offset);
            location++;
        }

        m_VertexBuffers.push_back(vbo);
    }

    void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer> &ibo)
    {
        glBindVertexArray(m_RendererID);
        ibo->Bind();
    }
}