#include "GlyptoCore/Platform.h"

namespace Glypto
{
    void Platform::InitializePlatform(const char *name, uint16_t width, uint16_t height)
    {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        {
            Logger::GLYPTO_CRITICAL("Unable to initialize SDL2!");
            std::exit(-1);
        }

        m_Window = SDL_CreateWindow(
            name,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            width,
            height,
            SDL_WINDOW_OPENGL);

        if (!m_Window)
        {
            Logger::GLYPTO_CRITICAL("Unable to initialize SDL2 window!");
            std::exit(-1);
        }

        // Hardcoded OpenGL context for now
        m_GraphicsContext = std::make_unique<OpenGLContext>(m_Window);
        m_GraphicsContext->InitializeContext();

        // Copy and save props
        m_Props.name = name;
        m_Props.width = width;
        m_Props.height = height;
    }

    void Platform::DestroyPlatform()
    {
        Logger::GLYPTO_INFO("Shutting down SDL2...");
        SDL_DestroyWindow(m_Window);
        SDL_Quit();
    }

    void Platform::UpdateWindowBuffers()
    {
        m_GraphicsContext->SwapWindowBuffers();
    }

}