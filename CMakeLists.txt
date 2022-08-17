cmake_minimum_required(VERSION 3.22)
project(ant_test LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 11)

add_compile_options(-O0 -ggdb)
add_compile_options(-Werror -Wno-attributes -Wenum-compare -Wno-deprecated-declarations)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ANT-SDK_PC.3.5/ANT_LIB)

add_executable(${PROJECT_NAME}
        main.cpp
        ant_receive_ch.cpp)

target_link_libraries (${PROJECT_NAME} LINK_PUBLIC ANT_LIB)
