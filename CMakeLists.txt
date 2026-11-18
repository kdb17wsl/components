cmake_minimum_required(VERSION 3.16)

project(components
    VERSION 0.1.0
    DESCRIPTION "Personal C++ component library"
    LANGUAGES CXX
)

add_library(components INTERFACE)
add_library(components::components ALIAS components)
target_include_directories(components INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>"
)
target_compile_features(components INTERFACE cxx_std_20)

include(CTest)
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
