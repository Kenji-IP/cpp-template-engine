#include "Assert.h"

#include "Engine/Platform/IO/PlatformIO.h"

extern "C" void* memcpy(void*, const void*, usize);

namespace Engine::Internal
{
    static constexpr const char* ExtractFileName(const char* fullPath) noexcept
    {
        if (!fullPath) return nullptr;
    
        usize size = __builtin_strlen(fullPath);
        for (usize i = size; i > 0; --i)
            if (fullPath[i - 1] == '/' || fullPath[i - 1] == '\\') 
                return fullPath + i;
    
        return fullPath;
    }

    void Assert(const char* condition, const char* file, const char* line, const char* msg ) noexcept
    {
        char buffer[128];
        usize size = 0;

        auto Append = [&](const char* str) -> void {
            usize len = __builtin_strlen(str);
            usize remaining = sizeof(buffer) - size;
            usize copySize = (len < remaining) ? len : remaining;
            if (copySize == 0) return;
            ::memcpy(buffer + size, str, copySize);
            size += copySize;
        };

        Append("\x1b[1;4;95m[ASSERT]\x1b[0m ");
        Append("( ");
        Append(condition);
        Append(" )");
        if (msg)
        {
           Append(" -> \x1b[1;91m"); 
           Append(msg);
           Append("\x1b[0m");
        }
        Append(" [");
        Append(ExtractFileName(file));
        Append(":");
        Append(line);
        Append("]\n");

        Platform::IO::ConsoleOut(buffer, size);
    }
}