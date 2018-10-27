cmake_minimum_required(VERSION 3.12)
project(L3_2RPNcomplex)

set(CMAKE_CXX_STANDARD 17)

add_executable(L3_2RPNcomplex main.cpp RPNCalculator.h pvector.h persistence_traits.h fraction.h)