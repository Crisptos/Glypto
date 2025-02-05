#pragma once
#include <memory>
#include "GlyptoCore/InputManager.h"
#include "GlyptoCore/Platform.h"
#include "GlyptoCore/Core.h"
#include "GlyptoCore/Logger.h"
#include "GlyptoCore/Event.h"
#include "GlyptoCore/Renderer/Renderer.h"

namespace Glypto
{
    class GLYPTO_API Application : public EventObserver
    {
    public:
        Application(const char* name, uint16_t width, uint16_t height);
        virtual ~Application();

        void Run();

        // Observer overridables
        void OnNotify(Event& event) override;

    private:
        uint8_t m_IsRunning = SDL_TRUE;
        uint8_t m_IsMinimized = SDL_FALSE;
        InputManager m_InputManager;
        Platform m_Platform;
        std::shared_ptr<VertexBuffer> test_vbo;
        std::shared_ptr<IndexBuffer> test_ibo;
        std::unique_ptr<VertexArray> test_vao;
    };
}

Glypto::Application *CreateApplication();