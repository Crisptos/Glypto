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
            0.0f, 0.5f, 0.0f
        };
        test = VertexBuffer::Create(vertices, sizeof(vertices));
        test->Bind();
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
        // TEST CODE ONLY
        delete test;
        // TEST CODE ONLY
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