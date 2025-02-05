#include "GlyptoCore/Application.h"

namespace Glypto
{
    Application::Application(const char *name, uint16_t width, uint16_t height)
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
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f};

        const char *vertexShaderSource = "#version 330 core\n"
                                         "layout (location = 0) in vec3 aPos;\n"
                                         "void main()\n"
                                         "{\n"
                                         "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                         "}\0";
        const char *fragmentShaderSource = "#version 330 core\n"
                                           "out vec4 FragColor;\n"
                                           "void main()\n"
                                           "{\n"
                                           "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                           "}\n\0";

        Shader test(vertexShaderSource, fragmentShaderSource);
        test.Bind();

        BufferLayout test_layout = {{"a_pos",
                                     ShaderDataType::FLOAT3}};

        test_vbo.reset(VertexBuffer::Create(vertices, sizeof(vertices)));
        test_vao.reset(VertexArray::Create());
        test_vao->Bind();
        test_vbo->SetLayout(test_layout);
        test_vao->AddVertexBuffer(test_vbo);

        // TEST CODE ONLY

        // TODO - Systems will be updated based on a layer system
        while (m_IsRunning)
        {
            if (!m_IsMinimized)
            {
                glClearColor(0.23f, 0.23f, 0.23f, 1.0f);
                glClear(GL_COLOR_BUFFER_BIT);
                glDrawArrays(GL_TRIANGLES, 0, 3);
                m_InputManager.ProcessInput();
                m_InputManager.UpdatePrevState();
                m_Platform.UpdateWindowBuffers();
            }
        }
    }

    void Application::OnNotify(Event &event)
    {
        switch (event.type)
        {
        case EventType::EVENT_APPLICATION_QUIT:
        {
            Logger::GLYPTO_INFO("Quitting application...");
            m_IsRunning = SDL_FALSE;
            event.handled = SDL_TRUE;
            break;
        }

        case EventType::EVENT_INPUT_KEYDOWN:
        {
            Logger::GLYPTO_INFO("Key %c was pressed...", event.keycode);
            event.handled = SDL_TRUE;
            break;
        }

        case EventType::EVENT_INPUT_KEYUP:
        {
            Logger::GLYPTO_INFO("Key %c was released...", event.keycode);
            event.handled = SDL_TRUE;
            break;
        }

        case EventType::EVENT_INPUT_MOUSE_BTNDOWN:
        {
            Logger::GLYPTO_INFO("Mouse Btn %d was pressed...", event.mouse_btn);
            event.handled = SDL_TRUE;
            break;
        }

        case EventType::EVENT_INPUT_MOUSE_BTNUP:
        {
            Logger::GLYPTO_INFO("Mouse Btn %d was released...", event.mouse_btn);
            event.handled = SDL_TRUE;
            break;
        }

        case EventType::EVENT_INPUT_MOUSE_MOTION:
        {
            Logger::GLYPTO_INFO("Mouse Pos is (X: %d, Y: %d)...", event.mouse_pos[0], event.mouse_pos[1]);
            event.handled = SDL_TRUE;
            break;
        }
        }
    }
}