cmake_minimum_required(VERSION 3.22)
project(Core)

set(CMAKE_CXX_STANDARD 23)

add_executable(Core app.cpp about.h)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(Test tests.cc)
target_link_libraries(Test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(Test)
