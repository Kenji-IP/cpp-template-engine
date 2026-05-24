#pragma once

#include "Engine/Utils/Defines.h"

#ifdef _MSC_VER
    #define ENGINE_DEBUG_BREAK() __debugbreak()
#else
    #define ENGINE_DEBUG_BREAK() __builtin_trap()
#endif

#define INTERNAL_STRINGIFY(x) #x
#define INTERNAL_TO_STRING(x) INTERNAL_STRINGIFY(x)

namespace Engine::Internal
{
    ENGINE_API void Assert(const char* condition, const char* file, const char* line, const char* msg = nullptr) noexcept;
}

#if ENGINE_BUILD_DEBUG || ENGINE_BUILD_RELEASE
    #define ENGINE_ASSERT(condition, ...) \
        do { \
            if (!(condition)) { \
                Engine::Internal::Assert(#condition, __FILE__, INTERNAL_TO_STRING(__LINE__) __VA_OPT__(,) __VA_ARGS__); \
                ENGINE_DEBUG_BREAK(); \
            } \
        } while (0)
#else
    #define ENGINE_ASSERT(condition, ...)
#endif