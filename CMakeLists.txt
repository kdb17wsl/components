cmake_minimum_required(VERSION 3.16)

project(components
    VERSION 0.1.0
    DESCRIPTION "Personal C++ component library"
    LANGUAGES CXX
)

file(GLOB_RECURSE COMPONENT_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

if(COMPONENT_SOURCES)
    add_library(components ${COMPONENT_SOURCES})
else()
    add_library(components INTERFACE)
endif()

add_library(components::components ALIAS components)
target_include_directories(components INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>"
    "$<INSTALL_INTERFACE:include>"
)
target_compile_features(components INTERFACE cxx_std_20)

include(CTest)
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
