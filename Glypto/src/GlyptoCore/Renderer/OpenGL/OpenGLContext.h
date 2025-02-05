#pragma once
#include "SDL2/SDL.h"
#include "glad/glad.h"
#include "GlyptoCore/Renderer/GraphicsContext.h"
#include "GlyptoCore/Core.h"
#include "GlyptoCore/Logger.h"

namespace Glypto
{
    class OpenGLContext : public GraphicsContext
    {
    public:
        OpenGLContext(SDL_Window *window_handle);

        void InitializeContext() override;
        void SwapWindowBuffers() override;

    private:
        SDL_Window *m_WindowHandle;
        SDL_GLContext m_Context;
    };
}