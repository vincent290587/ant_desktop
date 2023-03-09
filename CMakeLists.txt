cmake_minimum_required(VERSION 3.19)
project(ant_test LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_EXPORT_COMPILE_COMMANDS				ON)

set(CMAKE_INSTALL_PREFIX         "${CMAKE_SOURCE_DIR}/exe")
set(CMAKE_INSTALL_BINDIR         "${CMAKE_SOURCE_DIR}/AntPlusPlugin")

if ("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
    message(STATUS "Building without debug info")
else ()
    message(FATAL_ERROR "Wrong build type")
endif ()

if(NOT MSVC)
    add_compile_options(-O0)
    add_compile_options(-Werror -Wno-attributes -Wenum-compare -Wno-deprecated-declarations)
else()
    message("Using MSVC compiler")
endif()

include_directories(
        ./
        ${CMAKE_CURRENT_SOURCE_DIR}/AntPlusPlugin/Source/ThirdParty/AntPlusPluginLibrary
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ANT-SDK_PC.3.5/ANT_LIB ./libs/ant_plus)

set(SOURCES
        ue5_lib.cpp
        ant_receive_ch.cpp
        )

add_executable(${PROJECT_NAME}
        main.cpp
        ${SOURCES}
        )

target_link_libraries (${PROJECT_NAME} LINK_PUBLIC ANT_LIB)

add_library(${PROJECT_NAME}_DLL STATIC ${SOURCES})

target_link_libraries (${PROJECT_NAME}_DLL LINK_PUBLIC ANT_LIB)

#set_target_properties(${PROJECT_NAME}_DLL PROPERTIES
#        #PUBLIC_HEADER ue5_lib.h
#        VERSION ${PROJECT_VERSION}
#        SOVERSION 1
#        OUTPUT_NAME "ue5_lib"
#        XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY "Hex_Identity_ID_Goes_Here"
#        )

# TODO install to different folders on Mac / Linux
install(TARGETS ${PROJECT_NAME}_DLL ANT_LIB
        #        CONFIGURATIONS Release
        DESTINATION ${CMAKE_INSTALL_BINDIR}/Source/ThirdParty/AntPlusPluginLibrary/x64
        )
