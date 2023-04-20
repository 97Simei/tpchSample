

cmake_minimum_required(VERSION 3.1...3.6)
cmake_policy(SET CMP0079 NEW)
# -----------------------------------
# Project name, version & build type
# -----------------------------------
project(
        duckDBHelper
        DESCRIPTION "An example project with CMake"
        LANGUAGES CXX)



message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")



# ------------
# Dependencies
# ------------

find_package(Threads REQUIRED)
# Fetch Dependencies
include(FetchContent)
include(CMakePrintHelpers)
message(STATUS "Fetching DuckDB...")
FetchContent_Declare(
        duckdb
        GIT_REPOSITORY https://github.com/duckdb/duckdb.git
        GIT_TAG v0.7.0
        CMAKE_ARGS -DBUILD_JEMALLOC_EXTENSION=FALSE
        BUILD_COMMAND "-DBUILD_BENCHMARK=1 -DBUILD_TPCH_EXTENSION=1 DISABLE_THREADS=0 BUILD_JEMALLOC_EXTENSION=0"
)

FetchContent_MakeAvailable(duckdb)
message(STATUS "Build type: ${BUILD_COMMAND}")

message("-- Duckdb Available")

find_library( # Sets the name of the path variable.
        log-lib
        log )


add_library( # Sets the name of the library.
        duckDBHelper

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        native-lib.cpp)



target_link_libraries( # Specifies the target library.
        duckDBHelper
        # Links the target library to the log library
        # included in the NDK.
        ${log-lib} )
add_dependencies(duckDBHelper duckdb)
target_link_libraries(duckDBHelper duckdb)
#include_directories(duckDBHelper duckdb/include/)
