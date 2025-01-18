#include "GlyptoCore/Logger.h"

namespace Glypto
{
    std::shared_ptr<spdlog::logger> Logger::s_CoreLogger;

    void Logger::InitializeLogger()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        s_CoreLogger = spdlog::stdout_color_mt("GLYPTO");
        s_CoreLogger->set_level(spdlog::level::trace);
    }
}