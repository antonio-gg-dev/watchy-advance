#pragma once

#include <cstdint>
#include <string>

namespace watchy_advance
{

class Time
{
public:
    Time(std::uint8_t hour, std::uint8_t minute);

    std::string format() const;

private:
    std::uint8_t hour_;
    std::uint8_t minute_;
};

}
