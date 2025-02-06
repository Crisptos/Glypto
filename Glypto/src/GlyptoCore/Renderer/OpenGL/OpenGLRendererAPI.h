#pragma once
#include "GlyptoCore/Renderer/RendererAPI.h"

namespace Glypto
{
    class OpenGLRendererAPI : public RendererAPI
    {
    public:
        OpenGLRendererAPI() {}
        void SetClearColor(glm::vec4& clear_color) const override;
        void Clear() const override;
        void IndexedDraw(const std::shared_ptr<VertexArray>& vao) const override;
    private:
    };
}