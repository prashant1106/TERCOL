cmake_minimum_required(VERSION 3.31)

set(CMAKE_CXX_STANDARD 20)

project(TERCOL VERSION 1.0.0 LANGUAGES CXX)

# Set header-only library
add_library(tercol INTERFACE
        examples/demo.cpp
)
target_include_directories(tercol INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# Installation support
include(GNUInstallDirs)
install(TARGETS tercol EXPORT tercolTargets)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# Exporting from build tree
install(EXPORT tercolTargets
        FILE tercolTargets.cmake
        NAMESPACE tercol::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/tercol
)

