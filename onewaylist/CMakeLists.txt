set(LIB_NAME MYLIST)
project(${LIB_NAME})

aux_source_directory(src SRC_FILES)
add_library(${LIB_NAME} SHARED ${SRC_FILES})
target_include_directories(${LIB_NAME} PUBLIC include)

target_compile_options(${LIB_NAME} PRIVATE "${CMAKE_CXX_FLAGS}" "-Wall" "-Wno-comment" "-Weffc++" )

#add_subdirectory(ut)