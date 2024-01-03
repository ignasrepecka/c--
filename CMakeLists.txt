cmake_minimum_required(VERSION 3.28.1)

# Set the compilers before the project() line
set(CMAKE_CXX_COMPILER "C:/MinGW/bin/g++.exe")
set(CMAKE_C_COMPILER "C:/MinGW/bin/gcc.exe")

project(v1.0)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(v1.0 ${SOURCES})
