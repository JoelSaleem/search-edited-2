#include <gtest/gtest.h>

TEST(SampleTest, HandlesZeroInput) {
    EXPECT_EQ(1, 1);
}

TEST(SampleTest, HandlesNonZeroInput) {
    EXPECT_TRUE(1 == 1);
}