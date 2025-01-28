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
        // TODO - Used only for testing the input. Window will be handled after
        SDL_Window* window;
        SDL_CreateWindow("TEST", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, NULL);
        while(m_IsRunning)
        {
            m_InputManager.ProcessInput();
            m_InputManager.UpdatePrevState();
        }
    }

    void Application::OnNotify(Event event)
    {
        if(event.type == EVENT_APPLICATION_QUIT)
        {
            Logger::GLYPTO_INFO("Quitting application...");
            m_IsRunning = false;
        }

        if(event.type == EVENT_INPUT_KEYDOWN)
        {
            Logger::GLYPTO_INFO("Key %c was pressed...", event.keycode);
        }

        if(event.type == EVENT_INPUT_KEYUP)
        {
            Logger::GLYPTO_INFO("Key %c was released...", event.keycode);
        }

        if(event.type == EVENT_INPUT_MOUSE_BTNDOWN)
        {
            Logger::GLYPTO_INFO("Mouse Btn %d was pressed...", event.mouse_btn);
        }

        if(event.type == EVENT_INPUT_MOUSE_BTNUP)
        {
            Logger::GLYPTO_INFO("Mouse Btn %d was released...", event.mouse_btn);
        }

        if(event.type == EVENT_INPUT_MOUSE_MOTION)
        {
            Logger::GLYPTO_INFO("Mouse Pos is (X: %d, Y: %d)...", event.mouse_pos[0], event.mouse_pos[1]);
        }
    }
}