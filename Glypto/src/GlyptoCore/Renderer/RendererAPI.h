#pragma once
#include "glm/glm.hpp"
#include "GlyptoCore/Renderer/VertexArray.h"
#include <stdint.h>
#include <memory>

namespace Glypto
{
    class RendererAPI
    {
    public:
        enum class Backend : uint8_t
        {
            NONE,
            OPENGL
        };

        virtual void SetClearColor(glm::vec4& clear_color) const = 0;
        virtual void Clear() const = 0;
        virtual void IndexedDraw(const std::shared_ptr<VertexArray>& vao) const = 0;

        static Backend GetBackend();

    private:
        static Backend s_Backend;
    };

}