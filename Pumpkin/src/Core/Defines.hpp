#pragma once

#if defined(_WIN64) || defined(__GNUC__)
    #ifdef _WIN64
        #ifdef PUMPKIN_LIB
            #define PUMPKIN_API __declspec(dllexport)
        #else
            #define PUMPKIN_API __declspec(dllimport)
        #endif
    #endif
    
    #ifdef __GNUC__
        #ifdef PUMPKIN_LIB
            #define PUMPKIN_API __attribute__((visibility("default")))
        #else
            #define PUMPKIN_API
        #endif
    #endif
#else
    #error Pumpkin only supports Linux & Windows!
#endif

#ifdef PUMPKIN_ASSERTS
    #define PUMPKIN_ASSERT(x, ...) { if(!(x)) { PUMPKIN_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
    #define PUMPKIN_CORE_ASSERT(x, ...) { if(!(x)) { PUMPKIN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
    #define PUMPKIN_ASSERT(x, ...)
    #define PUMPKIN_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
#define PUMPKIN_BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)