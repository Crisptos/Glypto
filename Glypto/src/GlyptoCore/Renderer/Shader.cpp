#include "GlyptoCore/Renderer/Shader.h"
#include "GlyptoCore/Logger.h"

namespace Glypto
{
    void Shader::CompileShaderStage(const std::string &src, GLenum type)
    {
        uint32_t shader_stage_id = glCreateShader(type);
        const GLchar* src_input = src.c_str();
        glShaderSource(shader_stage_id, 1, &src_input, NULL);
        glCompileShader(shader_stage_id);

        int32_t success;
        char log[1024];
        glGetShaderiv(shader_stage_id, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader_stage_id, sizeof(log), NULL, log);
            Logger::GLYPTO_ERROR("Error compiling shader: %s", log);
            return;
        }

        glAttachShader(m_RendererID, shader_stage_id);
        glDeleteShader(shader_stage_id);
    }

    void Shader::LinkShaderProgram()
    {
        glLinkProgram(m_RendererID);

        int32_t success;
        char log[1024];
        glGetProgramiv(m_RendererID, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(m_RendererID, sizeof(log), NULL, log);
            Logger::GLYPTO_ERROR("Error linking shader program: %s", log);
        }

        glValidateProgram(m_RendererID);

        glGetProgramiv(m_RendererID, GL_VALIDATE_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(m_RendererID, sizeof(log), NULL, log);
            Logger::GLYPTO_ERROR("Error validating shader program: %s", log);
        }
    }
}