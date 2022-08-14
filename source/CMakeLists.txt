cmake_minimum_required(VERSION 3.22)
project(Core)

set(CMAKE_CXX_STANDARD 23)
find_package(Boost 1.80 COMPONENTS json thread REQUIRED)
include_directories( ${Boost_INCLUDE_DIR} )
add_executable(Core main.cpp
        about.h authorization.h network.h headers.h application.h environment.h session.h server.h
)
target_link_libraries(Core Boost::thread)

enable_testing()
find_package(GTest REQUIRED)

add_executable(Test tests.cc
        about.h authorization.h network.h headers.h application.h environment.h session.h server.h
)
target_link_libraries(Test GTest::gtest_main Boost::thread)

include(GoogleTest)
gtest_discover_tests(Test)
