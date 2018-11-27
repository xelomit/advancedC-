cmake_minimum_required(VERSION 3.12)
project(L5_4Metaprogramming)

set(CMAKE_CXX_STANDARD 17)

add_executable(L5_4Metaprogramming main.cpp gcd_meta.h fibonacci_meta.cpp fibonacci_meta.h)