cmake_minimum_required(VERSION 3.22)
project(ant_test)

set(CMAKE_CXX_STANDARD 11)

add_compile_options(-Werror -Wno-attributes -Wenum-compare -Wno-deprecated-declarations)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ANT-SDK_PC.3.5/ANT_LIB)

add_executable(${PROJECT_NAME}
        ANT-SDK_PC.3.5/DEMO_HR_RECEIVER/demo_hr_receiver.cpp
#        main.cpp
        )

target_link_libraries (${PROJECT_NAME} LINK_PUBLIC ANT_LIB)
