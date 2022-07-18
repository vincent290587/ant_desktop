cmake_minimum_required(VERSION 3.7.2)

project(ANT_DLL VERSION 3.5.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)

add_compile_options(-Werror -Wno-attributes -Wenum-compare -Wno-deprecated-declarations)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ANT_DLL)

set(SDK_INCLUDES
        ${CMAKE_CURRENT_SOURCE_DIR}/ANT_LIB/
        ${CMAKE_CURRENT_SOURCE_DIR}/ANT_LIB/inc
        ${CMAKE_CURRENT_SOURCE_DIR}/ANT_LIB/common
        ${CMAKE_CURRENT_SOURCE_DIR}/ANT_LIB/libraries
        ${CMAKE_CURRENT_SOURCE_DIR}/ANT_LIB/software/system
        ${CMAKE_CURRENT_SOURCE_DIR}/ANT_LIB/software/serial
        ${CMAKE_CURRENT_SOURCE_DIR}/ANT_LIB/software/USB
        ${CMAKE_CURRENT_SOURCE_DIR}/ANT_LIB/software/USB/devices
        ${CMAKE_CURRENT_SOURCE_DIR}/ANT_LIB/software/USB/device_handles
        ${CMAKE_CURRENT_SOURCE_DIR}/ANT_LIB/DEMO_HR_RECEIVER
        )

include_directories(${SDK_INCLUDES})

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ANT_LIB)

add_library(ANT_DLL SHARED ANT_DLL/ant.cpp ANT_DLL/ant.h)

#target_include_directories(ANT_DLL PUBLIC ${SDK_INCLUDES})

target_link_libraries(${PROJECT_NAME} LINK_PUBLIC ANT_LIB)

set_target_properties(ANT_DLL PROPERTIES
        PUBLIC_HEADER ANT_DLL/ant.h
        VERSION ${PROJECT_VERSION}
        SOVERSION 1
        OUTPUT_NAME "ant_dll"
        XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY "Hex_Identity_ID_Goes_Here"
        )
