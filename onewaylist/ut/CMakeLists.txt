set(APP_NAME UT_MYLIST)
project(${APP_NAME})

aux_source_directory(src SRC_FILES)
add_executable(${APP_NAME} ${SRC_FILES})

target_link_libraries(${APP_NAME} PRIVATE MYLIST)
target_link_libraries(${APP_NAME} gtest)
target_link_libraries(${APP_NAME} gmock)
target_link_libraries(${APP_NAME} gmock_main)
target_include_directories(${APP_NAME} PRIVATE include)