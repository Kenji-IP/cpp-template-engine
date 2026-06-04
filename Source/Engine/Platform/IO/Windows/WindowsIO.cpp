#ifdef ENGINE_PLATFORM_WINDOWS

#include "WindowsIO.h"

#ifndef WIN32_LEAN_AND_MEAN
    #define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
    #define NOMINMAX
#endif
#include <windows.h>

namespace Windows::IO 
{
    void ConsoleOut(const void* buffer, usize size) noexcept
    {
        static HANDLE handle = ::GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD written;
        ::WriteFile(handle, buffer, static_cast<DWORD>(size), &written, nullptr);
    }
}

#endif