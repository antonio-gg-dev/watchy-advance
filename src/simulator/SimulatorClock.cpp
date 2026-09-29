#include "SimulatorClock.h"

#include <ctime>

namespace watchy_advance
{

Time SimulatorClock::now() const
{
    const std::time_t current_time = std::time(nullptr);
    const std::tm* local_time = std::localtime(&current_time);

    return {static_cast<std::uint8_t>(local_time->tm_hour), static_cast<std::uint8_t>(local_time->tm_min)};
}

}
