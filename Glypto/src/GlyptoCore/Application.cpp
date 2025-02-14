#include "GlyptoCore/Application.h"

namespace Glypto
{
    Application::Application(const char *name, uint16_t width, uint16_t height)
        : test_cam(0, 800, 0, 600, {0.0f, 0.0f, 0.0f}, 0.0f)
    {
        // Subsystem initialization
        m_Platform.InitializePlatform(name, width, height);

        // Event listening setup
        m_InputManager.AddObserver(this);

    }

    Application::~Application()
    {
        // Subsystem de-initialization
        m_Platform.DestroyPlatform();
    }

    void Application::Run()
    {
        // TEST CODE ONLY
        glViewport(0, 0, 800, 600);
        float vertices[] = {
            // POS            // COLOR
            -0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
            0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
            0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
            -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f
        };

        float vertices_ortho[] = {
            // POS            // COLOR
            100.0f, 400.0f, 1.0f, 1.0f, 0.0f, 0.0f,
            400.0f, 400.0f, 1.0f, 0.0f, 1.0f, 0.0f,
            400.0f, 100.0f, 1.0f, 0.0f, 0.0f, 1.0f,
            100.0f, 100.0f, 1.0f, 1.0f, 0.0f, 1.0f
        };

        uint32_t indices[] = {
            0, 1, 3,
            3, 1, 2};

        const char *vertexShaderSource = "#version 330 core\n"
                                         "layout (location = 0) in vec3 a_pos;\n"
                                         "layout (location = 1) in vec3 a_color;\n"
                                         "out vec4 vert_color;\n"
                                         "uniform mat4 u_proj_view;\n"
                                         "void main()\n"
                                         "{\n"
                                         "   gl_Position = u_proj_view * vec4(a_pos.x, a_pos.y, a_pos.z, 1.0);\n"
                                         "   vert_color = vec4(a_color, 1.0f);\n"
                                         "}\0";

        const char *fragmentShaderSource = "#version 330 core\n"
                                           "in vec4 vert_color;\n"
                                           "out vec4 frag_color;\n"
                                           "void main()\n"
                                           "{\n"
                                           "   frag_color = vert_color;\n"
                                           "}\n\0";

        Shader test_shader(vertexShaderSource, fragmentShaderSource);

        BufferLayout test_layout = {
            {"a_pos", ShaderDataType::FLOAT3},
            {"a_color", ShaderDataType::FLOAT3}
        };

        test_vao.reset(VertexArray::Create());
        test_vao->Bind();
        test_vbo.reset(VertexBuffer::Create(vertices_ortho, sizeof(vertices_ortho)));
        test_ibo.reset(IndexBuffer::Create(indices, sizeof(indices)));
        test_vbo->SetLayout(test_layout);
        test_vao->SetIndexBuffer(test_ibo);
        test_vao->AddVertexBuffer(test_vbo);

        // TEST CODE ONLY

        // TODO - Systems will be updated based on a layer system
        while (m_IsRunning)
        {
            if (!m_IsMinimized)
            {
                m_InputManager.ProcessInput();
                m_InputManager.UpdatePrevState();
                Renderer::BeginScene();
                Renderer::SubmitScene(test_vao, test_shader, test_cam);
                Renderer::EndScene();
                m_Platform.UpdateWindowBuffers();
            }
        }
    }
}