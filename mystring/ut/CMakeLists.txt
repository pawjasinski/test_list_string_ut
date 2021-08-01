set(UT_NAME UT_MYSTRING)
project(${UT_NAME})

aux_source_directory(src UT_FILES)
add_executable(${UT_NAME} ${UT_FILES})

target_link_libraries(${UT_NAME} PRIVATE MYSTRING)
target_link_libraries(${UT_NAME} PRIVATE gtest)
target_link_libraries(${UT_NAME} PRIVATE gtest_main)
target_link_libraries(${UT_NAME} PRIVATE gmock)
target_link_libraries(${UT_NAME} PRIVATE gmock_main)
target_include_directories(${UT_NAME} PRIVATE include)