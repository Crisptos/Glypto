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

        // TODO - renderer is hardcoded to OPENGL ctx at the moment
        SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
        // Also request a depth buffer
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

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

        m_ContextGL = SDL_GL_CreateContext(m_Window);

        if (!m_ContextGL)
        {
            Logger::GLYPTO_CRITICAL("Unable to initialize SDL2 opengl context!");
            std::exit(-1);
        }

        // TODO - Hardcoded GLAD initialization change in future
        if(!gladLoadGLLoader(SDL_GL_GetProcAddress))
        {
            Logger::GLYPTO_CRITICAL("Unable to load OpenGL functions!");
        }

        Logger::GLYPTO_INFO("Default OpenGL Renderer Initialized");
        Logger::GLYPTO_INFO("Vendor: %s", glGetString(GL_VENDOR));
        Logger::GLYPTO_INFO("Renderer: %s", glGetString(GL_RENDERER));
        Logger::GLYPTO_INFO("Version: %s", glGetString(GL_VERSION));

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

}