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

TEST(UtilsTests, NoQueryParams)
{
    auto x = *utils::getQueryParams("/abc/123");
    EXPECT_TRUE(x.size() == 0);
}

TEST(UtilsTests, TwoValidQueryParams)
{
    auto x = *utils::getQueryParams("/abc/123?k1=v1&k2=v2");

    EXPECT_TRUE(x.size() == 2);
    EXPECT_EQ(x["k1"], "v1");
    EXPECT_EQ(x["k2"], "v2");
}

TEST(UtilsTests, NoSeparatorQP)
{
    EXPECT_THROW(utils::getQueryParams("/abc/123?k1=v1=k2=v2"), std::runtime_error);
}

TEST(UtilsTests, TooManyQuestionMarksQP)
{
    EXPECT_THROW(utils::getQueryParams("/abc/123?k1=v1?k2=v2"), std::runtime_error);
}

TEST(UtilsTests, TooManyAmperQP)
{
    EXPECT_THROW(utils::getQueryParams("/abc/123?k1&v1&k2=v2"), std::runtime_error);
}

TEST(UtilsTests, EmptyKey)
{
    EXPECT_THROW(utils::getQueryParams("/abc/123?&v1&k2=v2"), std::runtime_error);
}

TEST(UtilsTests, EmptyVal)
{
    EXPECT_THROW(utils::getQueryParams("/abc/123?k=v&k2="), std::runtime_error);
}

TEST(UtilsTests, EmptyValSecond)
{
    EXPECT_THROW(utils::getQueryParams("/abc/123?k=v&=val"), std::runtime_error);
}

TEST(UtilsTests, EmptyQP)
{
    EXPECT_THROW(utils::getQueryParams(""), std::runtime_error);
}

TEST(UtilsTests, QPNotStartingWithSlash)
{
    EXPECT_THROW(utils::getQueryParams("abc?qp=1&qp2=2"), std::runtime_error);
}

