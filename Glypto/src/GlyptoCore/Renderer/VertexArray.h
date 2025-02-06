#pragma once
#include <memory>
#include "GlyptoCore/Renderer/Buffer.h"

namespace Glypto
{
    class VertexArray
    {
    public:
        virtual ~VertexArray() {}

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vbo) = 0;
        virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& ibo) = 0;
        virtual std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() = 0;
        virtual std::shared_ptr<IndexBuffer>& GetIndexBuffer() = 0;

        static VertexArray* Create();
    };
}