#pragma once
#include "glad/glad.h"
#include <string>
#include <stdint.h>

namespace Glypto
{
    enum class ShaderType : uint8_t
    {
        VERTEX,
        FRAGMENT,
        GEOMETRY
    };

    // Shader is hardcoded to using GLSL for the time being
    // TODO - Create abstraction to allow for either HLSL or GLSL, use this class as a base
    class Shader
    {
    public:
        Shader(const std::string &vert_src, const std::string &frag_src)
        {
            m_RendererID = glCreateProgram();
            CompileShaderStage(vert_src, GL_VERTEX_SHADER);
            CompileShaderStage(frag_src, GL_FRAGMENT_SHADER);
            LinkShaderProgram();
        };

        ~Shader() { glDeleteProgram(m_RendererID); };

        void Bind() const { glUseProgram(m_RendererID); }
        void Unbind() const { glUseProgram(0); }

        void UploadUniformBool(std::string &name, uint8_t &value) const { glUniform1i(glGetUniformLocation(m_RendererID, name.c_str()), value); }
        void UploadUniformInt(std::string &name, uint32_t &value) const { glUniform1i(glGetUniformLocation(m_RendererID, name.c_str()), value); }
        void UploadUniformFloat(std::string &name, float &value) const { glUniform1f(glGetUniformLocation(m_RendererID, name.c_str()), value); }
        // TODO - Add vec and mats

    private:
        void CompileShaderStage(const std::string &src, GLenum type); // TODO - Use ShaderType enum class
        void LinkShaderProgram();
        uint32_t m_RendererID;
    };
}