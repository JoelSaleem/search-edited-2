cmake_minimum_required(VERSION 3.16)

project(Search VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(TARGET_NAME Search)

find_package(PkgConfig REQUIRED)
pkg_check_modules(PQXX REQUIRED libpqxx)

link_directories(${PQXX_LIBRARY_DIRS})

find_package(PostgreSQL REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)
find_package(OpenSSL REQUIRED)
find_package(cpprestsdk REQUIRED)

add_executable(${TARGET_NAME}
    src/main.cpp
    src/db/DBConn.cpp
)

target_include_directories(${TARGET_NAME} PRIVATE
    ${Boost_INCLUDE_DIR}
    ${OPENSSL_INCLUDE_DIR}
    ${PQXX_INCLUDE_DIRS}
    ${PostgreSQL_INCLUDE_DIRS}
    include
)

target_link_libraries(${TARGET_NAME}
  PRIVATE
    cpprestsdk::cpprest
    Boost::system
    OpenSSL::SSL
    OpenSSL::Crypto
    ${PQXX_LIBRARIES}
    ${PostgreSQL_LIBRARIES}
)
