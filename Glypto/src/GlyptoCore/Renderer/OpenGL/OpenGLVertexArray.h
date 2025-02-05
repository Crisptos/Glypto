#pragma once
#include <vector>
#include "glad/glad.h"
#include "GlyptoCore/Renderer/VertexArray.h"

namespace Glypto
{
    class OpenGLVertexArray : public VertexArray
    {
    public:
        OpenGLVertexArray() { glGenVertexArrays(1, &m_RendererID); }
        virtual ~OpenGLVertexArray() { glDeleteVertexArrays(1, &m_RendererID); }

        void Bind() const override;
        void Unbind() const override;

        void AddVertexBuffer(const std::shared_ptr<VertexBuffer> &vbo) override;
        void SetIndexBuffer(const std::shared_ptr<IndexBuffer> &ibo) override;
    private:
        uint32_t m_RendererID;
        std::vector<std::shared_ptr<VertexBuffer>> m_VertexBuffers;
        std::shared_ptr<IndexBuffer> m_IndexBuffer;

    };
}