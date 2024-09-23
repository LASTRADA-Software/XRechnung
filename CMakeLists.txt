cmake_minimum_required(VERSION 3.27 FATAL_ERROR)
project(XRechnung VERSION "0.0.1" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src/XRechnung)
add_subdirectory(src/tests)

enable_testing()
