#include "PlatformIO.h"

#ifdef ENGINE_PLATFORM_WINDOWS
    #include "Engine/Platform/IO/Windows/WindowsIO.h"
    namespace Backend = Windows;
#else
    #error Platform not supported!
#endif

namespace Platform::IO 
{
    void ConsoleOut(const void* buffer, usize size) noexcept
    {
        Backend::IO::ConsoleOut(buffer, size);
    }
}