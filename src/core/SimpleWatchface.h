#pragma once

#include <string>

#include "Clock.h"

namespace watchy_advance
{

class SimpleWatchface
{
    public:
        explicit SimpleWatchface(const Clock& clock);

        std::string render() const;

    private:
        const Clock& clock_;
};

}
