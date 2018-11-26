cmake_minimum_required(VERSION 3.12)
project(L5_1FileLockerRPN)

set(CMAKE_CXX_STANDARD 17)

add_executable(L5_1FileLockerRPN main.cpp FileLocker.cpp FileLocker.h fraction.h persistence_traits.h pvector.h RPNCalculator.h)