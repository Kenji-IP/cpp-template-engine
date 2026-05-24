#pragma once

#include "Engine/Utils/Types.h"

namespace Windows::IO 
{
    void ConsoleOut(const void* buffer, usize size) noexcept;
}