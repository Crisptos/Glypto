#include "GlyptoCore/Application.h"

namespace Glypto
{
    Application::Application()
    {

    }

    Application::~Application()
    {

    }

    void Application::Run()
    {
        Logger::GLYPTO_INFO("Test Msg");
        Logger::GLYPTO_CRITICAL("Test with vars hi=%d", 4);
        Logger::GLYPTO_WARN("Test with vars hi=%d", 5);
        Logger::GLYPTO_DEBUG("Test with vars hi=%d", 6);
        Logger::GLYPTO_ERROR("Test with vars hi=%d and %d", 6, 8);
        Logger::GLYPTO_TRACE("Test with multiple vars hi=%d and string=%s", 4, "banana");
    }
}