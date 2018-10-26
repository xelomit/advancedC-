cmake_minimum_required(VERSION 3.12)
project(5_1EmulatingPointers)

set(CMAKE_CXX_STANDARD 17)

add_executable(5_1EmulatingPointers main.cpp dumbPointer.h smartPointer.h object.cpp object.h)