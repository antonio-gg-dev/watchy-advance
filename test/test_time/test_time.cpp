#include <unity.h>

#include "core/Time.h"

using watchy_advance::Time;

void setUp() {}

void tearDown() {}

void test_formats_single_digit_hour_and_minute()
{
    const Time time{9, 5};

    TEST_ASSERT_EQUAL_STRING("09:05", time.format().c_str());
}

void test_formats_midnight()
{
    const Time time{0, 0};

    TEST_ASSERT_EQUAL_STRING("00:00", time.format().c_str());
}

void test_formats_last_minute_of_day()
{
    const Time time{23, 59};

    TEST_ASSERT_EQUAL_STRING("23:59", time.format().c_str());
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(test_formats_single_digit_hour_and_minute);
    RUN_TEST(test_formats_midnight);
    RUN_TEST(test_formats_last_minute_of_day);

    return UNITY_END();
}
