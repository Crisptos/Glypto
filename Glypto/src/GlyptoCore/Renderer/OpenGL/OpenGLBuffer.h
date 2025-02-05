#pragma once
#include "glad/glad.h"
#include "GlyptoCore/Renderer/Buffer.h"

namespace Glypto
{
    class OpenGLVertexBuffer : public VertexBuffer
    {
    public:
        OpenGLVertexBuffer(float *vertices, uint32_t size);
        virtual ~OpenGLVertexBuffer();

        void Bind() const override;
        void Unbind() const override;

        void SetLayout(const BufferLayout& layout) override
        {
            m_BufferLayout = layout;
        }

        const BufferLayout& GetLayout() const override
        {
            return m_BufferLayout;
        }

    private:
        uint32_t m_RendererID;
        BufferLayout m_BufferLayout;
    };

    class OpenGLIndexBuffer : public IndexBuffer
    {
    public:
        OpenGLIndexBuffer(uint32_t *indices, uint32_t size);
        virtual ~OpenGLIndexBuffer();

        void Bind() const override;
        void Unbind() const override;

    private:
        uint32_t m_RendererID;
    };
}