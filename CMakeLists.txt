cmake_minimum_required(VERSION 3.27)
project(arithmetic)

set(CMAKE_CXX_STANDARD 14)

include_directories(gtest)
include_directories(include)

add_executable(arithmetic
        gtest/gtest-all.cc
        gtest/gtest.h
        include/arithmetic.h
        include/stack.h
        samples/main_arithmetic.cpp
        src/arithmetic.cpp
        test/test_arithmetic.cpp
        test/test_main.cpp
        test/test_stack.cpp
        include/stack.h)
