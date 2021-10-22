cmake_minimum_required(VERSION 3.20)
project(algorithm_cpp_courese_2021)

set(CMAKE_CXX_STANDARD 14)

include_directories(wheel/lib)

add_executable(algorithm_cpp_courese_2021
        running_space/main.cpp
        wheel/lib/queue_array.h
        wheel/lib/stack_array.h
        wheel/lib/stack_list.h
        wheel/src/queue_array.cpp
        wheel/src/stack_array.cpp
        wheel/src/stack_list.cpp wheel/lib/queue_list.h wheel/src/queue_list.cpp)
