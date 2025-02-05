#pragma once
#include <stdint.h>

namespace Glypto
{
    class Shader
    {
    public:
        Shader(const char* vert_src, const char* frag_src);
        ~Shader() {};
    private:
        uint32_t m_RendererID;
    };
}