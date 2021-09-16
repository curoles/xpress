cmake_minimum_required(VERSION 3.16)

project(XPRESS CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


#include(external_zlib.cmake)

#ExternalProject_Get_property(systemc INSTALL_DIR)
#set(SYSTEMC_LIB_DIR ${INSTALL_DIR}/lib)
#set(SYSTEMC_INCLUDE_DIR ${INSTALL_DIR}/include)
#message("SystemC installation path: ${INSTALL_DIR}")

#include_directories(${SYSTEMC_INCLUDE_DIR})

#file(DOWNLOAD
#    https://github.com/CLIUtils/CLI11/releases/download/v1.9.1/CLI11.hpp
#    ${PROJECT_SOURCE_DIR}/lib/CLI11.hpp
#)

include_directories(.)

set(CMAKE_CXX_FLAGS "-O2 -Werror -Wall -Wextra -fpic -flto -pipe -march=native")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG")

# Install inside the build directory.
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Do not strip RPATH during installation
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
#set(CMAKE_INSTALL_RPATH "${CMAKE_BINARY_DIR}/zlib_dir/lib")


#if(NOT TACHY_TOOLCHAIN_HOME)
#    message(FATAL_ERROR "TACHY_TOOLCHAIN_HOME not defined, do 'cmake -DTACHY_TOOLCHAIN_HOME=your_toolchain/install/set0 ../psim/'")
#endif()

#include_directories(${TACHY_TOOLCHAIN_HOME}/include)
#link_directories(${TACHY_TOOLCHAIN_HOME}/lib)

enable_testing()

add_subdirectory(xpress)
add_subdirectory(xpand)
add_subdirectory(test)
#add_subdirectory(doc)

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
