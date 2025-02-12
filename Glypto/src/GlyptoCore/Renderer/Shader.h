#pragma once
#include "glad/glad.h"
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
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

        void inline UploadUniformBool(const std::string &name, uint8_t &value) const { glUniform1i(glGetUniformLocation(m_RendererID, name.c_str()), value); }
        void inline UploadUniformInt(const std::string &name, uint32_t &value) const { glUniform1i(glGetUniformLocation(m_RendererID, name.c_str()), value); }
        void inline UploadUniformFloat(const std::string &name, float &value) const { glUniform1f(glGetUniformLocation(m_RendererID, name.c_str()), value); }
        void inline UploadUniformFloat2(const std::string &name, glm::vec2& value) const { glUniform2fv(glGetUniformLocation(m_RendererID, name.c_str()), 1, glm::value_ptr(value)); }
        void inline UploadUniformFloat3(const std::string &name, glm::vec3& value) const { glUniform3fv(glGetUniformLocation(m_RendererID, name.c_str()), 1, glm::value_ptr(value)); }
        void inline UploadUniformFloat4(const std::string &name, glm::vec4& value) const { glUniform4fv(glGetUniformLocation(m_RendererID, name.c_str()), 1, glm::value_ptr(value)); }
        void inline UploadUniformMat3(const std::string &name, glm::mat3& value) const { glUniformMatrix3fv(glGetUniformLocation(m_RendererID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value)); }
        void inline UploadUniformMat4(const std::string &name, glm::mat4& value) const { glUniformMatrix4fv(glGetUniformLocation(m_RendererID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value)); }
        // TODO - Add vec and mats

    private:
        void CompileShaderStage(const std::string &src, GLenum type); // TODO - Use ShaderType enum class
        void LinkShaderProgram();
        uint32_t m_RendererID;
    };
}