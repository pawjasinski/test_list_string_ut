cmake_minimum_required(VERSION 3.19)
project(string_and_list_ut_learn)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

add_executable(string_and_list_ut_learn main.cpp)

add_subdirectory(mystring)
add_subdirectory(onewaylist)
add_subdirectory(libs)

