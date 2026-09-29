#include "SimpleWatchface.h"

namespace watchy_advance
{

SimpleWatchface::SimpleWatchface(const Clock& clock) : clock_(clock) {}

std::string SimpleWatchface::render() const
{
    return clock_.now().format();
}

}
