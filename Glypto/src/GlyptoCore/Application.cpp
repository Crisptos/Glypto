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
        // TODO - Systems will be updated based on a layer system
        while (m_IsRunning)
        {
            if (!m_IsMinimized)
            {
                m_InputManager.ProcessInput();
                m_InputManager.UpdatePrevState();
                m_Platform.UpdateWindowBuffers();
            }
        }
    }

    void Application::OnNotify(Event event)
    {
        if (event.type == EVENT_APPLICATION_QUIT)
        {
            Logger::GLYPTO_INFO("Quitting application...");
            m_IsRunning = false;
        }

        if (event.type == EVENT_INPUT_KEYDOWN)
        {
            Logger::GLYPTO_INFO("Key %c was pressed...", event.keycode);
        }

        if (event.type == EVENT_INPUT_KEYUP)
        {
            Logger::GLYPTO_INFO("Key %c was released...", event.keycode);
        }

        if (event.type == EVENT_INPUT_MOUSE_BTNDOWN)
        {
            Logger::GLYPTO_INFO("Mouse Btn %d was pressed...", event.mouse_btn);
        }

        if (event.type == EVENT_INPUT_MOUSE_BTNUP)
        {
            Logger::GLYPTO_INFO("Mouse Btn %d was released...", event.mouse_btn);
        }

        if (event.type == EVENT_INPUT_MOUSE_MOTION)
        {
            Logger::GLYPTO_INFO("Mouse Pos is (X: %d, Y: %d)...", event.mouse_pos[0], event.mouse_pos[1]);
        }
    }
}