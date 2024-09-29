#pragma once

#include <memory>

#include "../Core/Defines.hpp"
#include "spdlog/spdlog.h"

namespace Pumpkin {
    class PUMPKIN_API Log {
    public:
        static void Init();
        
        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

// Core Macros
#define PUMPKIN_CORE_ERROR(...)     ::Pumpkin::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PUMPKIN_CORE_WARN(...)      ::Pumpkin::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PUMPKIN_CORE_INFO(...)      ::Pumpkin::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PUMPKIN_CORE_TRACE(...)     ::Pumpkin::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client Macros
#define PUMPKIN_ERROR(...)          ::Pumpkin::Log::GetClientLogger()->error(__VA_ARGS__)
#define PUMPKIN_WARN(...)           ::Pumpkin::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PUMPKIN_INFO(...)           ::Pumpkin::Log::GetClientLogger()->info(__VA_ARGS__)
#define PUMPKIN_TRACE(...)          ::Pumpkin::Log::GetClientLogger()->trace(__VA_ARGS__)