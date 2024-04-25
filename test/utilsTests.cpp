#include <gtest/gtest.h>
#include "utils.h"

TEST(UtilsTests, ValidBasicPath)
{
    std::string path = *utils::getPath("/abc");
    EXPECT_EQ(path, "/abc");
}

TEST(UtilsTests, ZeroLenPath)
{

    EXPECT_THROW(utils::getPath(""), std::runtime_error);
}

TEST(UtilsTests, DoesNotStartWithSlash)
{

    EXPECT_THROW(utils::getPath("abc"), std::runtime_error);
}

TEST(UtilsTests, NestedPath)
{
    std::string path = *utils::getPath("/abc/myResource");
    EXPECT_EQ(path, "/abc/myResource");
}

TEST(UtilsTests, NestedPathWithQueryParams)
{
    std::string path = *utils::getPath("/abc/myResource?key=val&key2=val2");
    EXPECT_EQ(path, "/abc/myResource");
}