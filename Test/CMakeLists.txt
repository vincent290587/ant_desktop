cmake_minimum_required(VERSION 3.22)
project(ant_load LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_EXPORT_COMPILE_COMMANDS				ON)

include_directories(
        ./
        ${CMAKE_CURRENT_SOURCE_DIR}/../AntPlusPlugin/Source/ThirdParty/AntPlusPluginLibrary
)

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../AntPlusPlugin/Source/ThirdParty/AntPlusPluginLibrary/x64)

add_executable(${PROJECT_NAME}
        main.cpp
        )

target_link_libraries(
        ${PROJECT_NAME}
        ant_test_DLL
)

