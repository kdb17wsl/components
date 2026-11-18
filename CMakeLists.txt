cmake_minimum_required(VERSION 3.16)

project(components LANGUAGES CXX)

add_library(components INTERFACE)
add_library(components::components ALIAS components)
target_include_directories(components INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>"
)
target_compile_features(components INTERFACE cxx_std_17)

include(CTest)
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
