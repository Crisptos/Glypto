#pragma once
#include <stdint.h>
#include "GlyptoCore/Renderer/RendererAPI.h"

namespace Glypto
{
    class RenderCommand
    {
    public:
        static inline void SetClearColor(glm::vec4 &clear_color) { s_RendererAPI->SetClearColor(clear_color); }
        static inline void Clear() { s_RendererAPI->Clear(); }
        static inline void IndexedDraw(const std::shared_ptr<VertexArray> &vao) { s_RendererAPI->IndexedDraw(vao); }

    private:
        static RendererAPI *s_RendererAPI;
    };
}