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
    }

    Application::~Application()
    {

    }

    void Application::Run()
    {
        Logger::GLYPTO_DEBUG("Key Array Size: %d", InputManager::GetInputState()->key_array_size);
    }
}