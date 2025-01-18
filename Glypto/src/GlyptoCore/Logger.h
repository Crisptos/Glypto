#pragma once

#include <memory>
#include <string>
#include <cstdarg>
#include "GlyptoCore/Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Glypto
{
    class GLYPTO_API Logger
    {

    public:
        static void InitializeLogger();

        static inline void GLYPTO_CRITICAL(const char* msg, ...)
        {
            va_list msg_args;
            va_start(msg_args, msg);
            s_CoreLogger->critical(
                FormatString(msg, msg_args)
            );
            va_end(msg_args);   
        }

        static inline void GLYPTO_ERROR(const char* msg, ...)
        {
            va_list msg_args;
            va_start(msg_args, msg);
            s_CoreLogger->error(
                FormatString(msg, msg_args)
            );
            va_end(msg_args);   
        }

        static inline void GLYPTO_WARN(const char* msg, ...)
        {
            va_list msg_args;
            va_start(msg_args, msg);
            s_CoreLogger->warn(
                FormatString(msg, msg_args)
            );
            va_end(msg_args);   
        }

        static inline void GLYPTO_INFO(const char* msg, ...)
        {
            va_list msg_args;
            va_start(msg_args, msg);
            s_CoreLogger->info(
                FormatString(msg, msg_args)
            );
            va_end(msg_args);   
        }

        static inline void GLYPTO_TRACE(const char* msg, ...)
        {
            va_list msg_args;
            va_start(msg_args, msg);
            s_CoreLogger->trace(
                FormatString(msg, msg_args)
            );
            va_end(msg_args);   
        }

        static inline void GLYPTO_DEBUG(const char* msg, ...)
        {
            va_list msg_args;
            va_start(msg_args, msg);
            s_CoreLogger->debug(
                FormatString(msg, msg_args)
            );
            va_end(msg_args);   
        }

    private:
        static std::string FormatString(const char* msg, va_list msg_args) 
        {
            char out_buf[1024];
            vsnprintf(out_buf, 1024, msg, msg_args);
            return std::string(out_buf);
        }

        static std::shared_ptr<spdlog::logger> s_CoreLogger;

    };
}