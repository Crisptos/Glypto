#include "GlyptoCore/Application.h"

namespace Glypto
{
    Application::Application()
    {
        if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
        {
            Logger::GLYPTO_CRITICAL("Unable to initialize SDL2!");
            exit(-1);
        }

        m_InputManager.AddObserver(this);
    }

    Application::~Application()
    {

    }

    void Application::Run()
    {
        Logger::GLYPTO_DEBUG("Key Array Size: %d", m_InputManager.m_Input.key_array_size);
        while(m_IsRunning)
        {
            m_InputManager.NotifyAll({APPLICATION_QUIT});
        }
    }

    void Application::OnNotify(Event e)
    {
        if(e.event_type == APPLICATION_QUIT)
        {
            Logger::GLYPTO_INFO("Quitting application...");
            m_IsRunning = false;
        }
    }
}