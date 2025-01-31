#pragma once
#include <string>

#include "SDL2/SDL.h"
#include "GlyptoCore/Core.h"
#include "GlyptoCore/Logger.h"

namespace Glypto
{
    typedef struct PlatformProps
    {
        std::string name;
        uint16_t width;
        uint16_t height;
    } PlatformProps;

    class Platform
    {
    public:
        void InitializePlatform(const char* name, uint16_t width, uint16_t height);
        void DestroyPlatform();

    private:
        SDL_Window *m_Window;
        PlatformProps m_Props;
        // TODO - Render Context
    };
}