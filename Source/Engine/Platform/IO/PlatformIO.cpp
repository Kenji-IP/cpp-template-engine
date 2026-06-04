#include "PlatformIO.h"

#ifdef ENGINE_PLATFORM_WINDOWS
    #include "Engine/Platform/IO/Windows/WindowsIO.h"
    namespace Backend = Windows;
#elif defined (ENGINE_PLATFORM_LINUX)
    #include "Engine/Platform/IO/Linux/LinuxIO.h"
    namespace Backend = Linux;
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