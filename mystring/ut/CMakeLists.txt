set(APP_NAME UT_MYSTRING)
project(${APP_NAME})

aux_source_directory(src SRC_FILES)
add_executable(${APP_NAME} ${SRC_FILES})

target_link_libraries(${APP_NAME} PRIVATE MYSTRING)
target_link_libraries(${APP_NAME} PRIVATE gtest)
target_link_libraries(${APP_NAME} PRIVATE gmock)
target_link_libraries(${APP_NAME} PRIVATE gmock_main)
target_include_directories(${APP_NAME} PRIVATE include)