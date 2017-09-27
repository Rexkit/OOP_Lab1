cmake_minimum_required(VERSION 3.8)
project(OOP_Lab1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp IniParser.cpp IniParser.h parser_exceptions.h)
add_executable(OOP_Lab1 ${SOURCE_FILES})