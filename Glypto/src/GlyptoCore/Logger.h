#pragma once
#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "GlyptoCore/Core.h"
#include <stdio.h>

namespace Glypto
{
    class GLYPTO_API Logger
    {

    public:
        Logger();
        ~Logger();
        void Output();
    private:

    };
}