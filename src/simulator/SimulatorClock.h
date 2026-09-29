#pragma once

#include "core/Clock.h"

namespace watchy_advance
{

class SimulatorClock final : public Clock
{
    public:
        Time now() const override;
};

}
