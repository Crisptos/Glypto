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

    private:
        uint32_t m_RendererID;
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