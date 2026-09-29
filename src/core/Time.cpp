#include "Time.h"

#include <cstdio>

namespace watchy_advance
{

Time::Time(const std::uint8_t hour, const std::uint8_t minute) : hour_(hour), minute_(minute) {}

std::string Time::format() const
{
    char formatted_time[8];
    std::snprintf(formatted_time,
                  sizeof(formatted_time),
                  "%02u:%02u",
                  static_cast<unsigned>(hour_),
                  static_cast<unsigned>(minute_));

    return formatted_time;
}

}
