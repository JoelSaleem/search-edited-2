add_executable(
    TestSuite 
    
    utilsTests.cpp 
    ../include/utils.h
    ../src/utils.cpp
)
target_include_directories(TestSuite PRIVATE ../include)

target_link_libraries(TestSuite gtest gtest_main)
add_test(NAME UtilsTests COMMAND TestSuite)

