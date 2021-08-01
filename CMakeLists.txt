cmake_minimum_required(VERSION 3.19)
set(APP_NAME string_and_list_ut_learn)
project(${APP_NAME})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

add_executable(${APP_NAME} main.cpp)
target_link_libraries(${APP_NAME} PRIVATE MYSTRING)

add_subdirectory(mystring)
add_subdirectory(onewaylist)
add_subdirectory(libs)

