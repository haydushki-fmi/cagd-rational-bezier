cmake_minimum_required(VERSION 3.28)

project(cagd-rational-bezier VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Tell MSVC to build using multiple processes.
# This may speed up compilation time significantly.
# For more information check:
# https://learn.microsoft.com/en-us/cpp/build/reference/mp-build-with-multiple-processes?view=msvc-170
add_compile_options($<$<CXX_COMPILER_ID:MSVC>:/MP>)

# Makes it easier to display some useful info
include(CMakePrintHelpers)

# Display some useful information
cmake_print_variables(CMAKE_MODULE_PATH)
cmake_print_variables(CMAKE_PREFIX_PATH)

# QT stuff
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)
qt_standard_project_setup()

include_directories("src")
add_subdirectory(src/app)
