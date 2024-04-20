cmake_minimum_required(VERSION 3.16)

project(
    Search
    VERSION 1.0.0
    LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


set(TARGET_NAME Search)

# add_subdirectory(LightYearsEngine)
# add_subdirectory(LightYearsGame)

add_executable(${TARGET_NAME}   
    src/main.cpp
)

