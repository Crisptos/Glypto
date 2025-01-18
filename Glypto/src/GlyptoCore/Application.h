#pragma once
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