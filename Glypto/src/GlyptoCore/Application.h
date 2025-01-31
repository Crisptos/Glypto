#pragma once
#include "SDL2/SDL.h"
#include "GlyptoCore/InputManager.h"
#include "GlyptoCore/Platform.h"
#include "GlyptoCore/Core.h"
#include "GlyptoCore/Logger.h"
#include "GlyptoCore/Event.h"

namespace Glypto
{
    class GLYPTO_API Application : public EventObserver
    {
    public:
        Application(const char* name, uint16_t width, uint16_t height);
        virtual ~Application();

        void Run();

        // Observer overridables
        void OnNotify(Event event) override;

    private:
        bool m_IsRunning = true;
        bool m_IsMinimized = false;
        InputManager m_InputManager;
        Platform m_Platform;
    };
}

Glypto::Application *CreateApplication();