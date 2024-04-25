#include <gtest/gtest.h>
#include "utils.h"

TEST(UtilsTests, HandlesZeroInput)
{
    std::string path = *utils::getPath("/abc");
    EXPECT_EQ(path, "/abc");
}
