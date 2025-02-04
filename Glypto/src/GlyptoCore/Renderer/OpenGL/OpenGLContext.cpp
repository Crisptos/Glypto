#include "GlyptoCore/Renderer/OpenGL/OpenGLContext.h"

namespace Glypto
{
    OpenGLContext::OpenGLContext(SDL_Window* window_handle)
    {
        m_WindowHandle = window_handle;

        // TODO - renderer is hardcoded to OPENGL ctx at the moment
        SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
        // Also request a depth buffer
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    }

    void OpenGLContext::InitializeContext()
    {
        m_Context = SDL_GL_CreateContext(m_WindowHandle);

        if (!m_Context)
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
    }

    void OpenGLContext::SwapWindowBuffers()
    {
        SDL_GL_SwapWindow(m_WindowHandle);
    }
}