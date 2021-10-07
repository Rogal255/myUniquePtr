#include <gtest/gtest.h>
#include "unique_ptr.hpp"

TEST(SampleTest, Trivial) {
    pr::unique_ptr test_ptr(new int(5));
    EXPECT_EQ(1, 1);
}
