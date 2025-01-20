#pragma once
#include "SDL2/SDL.h"
#include "GlyptoCore/InputManager.h"
#include "GlyptoCore/Core.h"
#include "GlyptoCore/Logger.h"

namespace Glypto
{
    class GLYPTO_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
    private:

    };
}

Glypto::Application* CreateApplication();