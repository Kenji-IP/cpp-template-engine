#pragma once

#ifdef ENGINE_PLATFORM_WINDOWS
    #ifdef ENGINE_DLL_EXPORT
        #define ENGINE_API __declspec(dllexport)
    #else
        #define ENGINE_API __declspec(dllimport)
    #endif
#else
    #define ENGINE_API
#endif

#define ENGINE_NODISCARD [[nodiscard]]

#define KiB(n) ((n##ULL) << 10)
#define MiB(n) ((n##ULL) << 20)
#define GiB(n) ((n##ULL) << 30)