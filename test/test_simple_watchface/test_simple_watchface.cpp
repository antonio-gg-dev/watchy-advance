#include <unity.h>

#include "core/Clock.h"
#include "core/SimpleWatchface.h"

using watchy_advance::Clock;
using watchy_advance::SimpleWatchface;
using watchy_advance::Time;

class FakeClock final : public Clock
{
    public:
        Time now() const override
        {
            return {9, 5};
        }
};

void setUp() {}

void tearDown() {}

void test_renders_current_time()
{
    FakeClock clock;
    const SimpleWatchface watchface{clock};

    TEST_ASSERT_EQUAL_STRING("09:05", watchface.render().c_str());
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(test_renders_current_time);

    return UNITY_END();
}
