cmake_minimum_required(VERSION 3.12)
project(3_4SimpleSpellChecker)

set(CMAKE_CXX_STANDARD 17)

add_executable(3_4SimpleSpellChecker main.cpp persistence_traits.h pset.h simple_spell_checker.cpp simple_spell_checker.h pvector.h)