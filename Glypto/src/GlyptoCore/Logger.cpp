#include "GlyptoCore/Logger.h"

namespace Glypto
{
    Logger::Logger()
    {
        if(SDL_Init(SDL_INIT_VIDEO) != 0)
        {
            exit(-1);
        }
    }

    // ESC[background_colour;Text_colourm output ESC[m”
    void Logger::Output()
    {
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "\033[31;49m Hello, world!\033[m");
    }

    Logger::~Logger()
    {
        SDL_Quit();
    }
}