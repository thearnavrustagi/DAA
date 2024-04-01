cmake_minimum_required(VERSION 3.9.1)
project(GroupAssignment1)
set(CMAKE_CXX_STANDARD 20)

include_directories(./include/*.hpp)
add_executable(group_assignment_1 ./lib/complex.cpp ./src/main.cpp)
