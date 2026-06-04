#ifdef ENGINE_PLATFORM_LINUX
#include "LinuxIO.h"

#include <unistd.h>

namespace Linux::IO
{
    void ConsoleOut(const void* buffer, usize size) noexcept
    {
        // TODO may use the return value
        ::write(STDOUT_FILENO, buffer, size);
    }
}

#endif