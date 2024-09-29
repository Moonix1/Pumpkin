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

#define BIT(x) (1 << x)