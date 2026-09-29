#include <ctime>
#include <string>

#include <unity.h>

#include "simulator/SimulatorClock.h"

using watchy_advance::SimulatorClock;

namespace
{

std::string local_time_format()
{
    const std::time_t current_time = std::time(nullptr);
    const std::tm* local_time = std::localtime(&current_time);
    char formatted_time[6];
    std::strftime(formatted_time, sizeof(formatted_time), "%H:%M", local_time);

    return formatted_time;
}

}

void setUp() {}

void tearDown() {}

void test_returns_current_local_time()
{
    const std::string before = local_time_format();
    SimulatorClock clock;
    const std::string actual = clock.now().format();
    const std::string after = local_time_format();

    TEST_ASSERT_TRUE(actual == before || actual == after);
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(test_returns_current_local_time);

    return UNITY_END();
}
