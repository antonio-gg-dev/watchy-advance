#pragma once

#include "Time.h"

namespace watchy_advance
{

class Clock
{
    public:
        virtual ~Clock() = default;

        virtual Time now() const = 0;
};

}
