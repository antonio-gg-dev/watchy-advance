#include <unity.h>

void setUp() {}

void tearDown() {}

void test_environment_runs()
{
    TEST_ASSERT_TRUE(true);
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(test_environment_runs);

    return UNITY_END();
}