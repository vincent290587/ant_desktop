cmake_minimum_required(VERSION 3.7.2)

project(ANT_LIB LANGUAGES C CXX)

set(SDK_INCLUDES
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
        ${CMAKE_CURRENT_SOURCE_DIR}/common
        ${CMAKE_CURRENT_SOURCE_DIR}/libraries
        ${CMAKE_CURRENT_SOURCE_DIR}/software/system
        ${CMAKE_CURRENT_SOURCE_DIR}/software/serial
        ${CMAKE_CURRENT_SOURCE_DIR}/software/USB
        ${CMAKE_CURRENT_SOURCE_DIR}/software/USB/devices
        ${CMAKE_CURRENT_SOURCE_DIR}/software/USB/device_handles
        ${CMAKE_CURRENT_SOURCE_DIR}/DEMO_HR_RECEIVER
)

include_directories(${SDK_INCLUDES})

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/common    SRCS)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/libraries    SRCS)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/software/system    SRCS)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/software/serial    SRCS)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/software/USB/devices    SRCS)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/software/USB/device_handles    SRCS)

add_library(ANT_LIB ${SDK_SRCS} ${SRCS})

target_include_directories(ANT_LIB PUBLIC ${SDK_INCLUDES})
