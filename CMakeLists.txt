# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
cmake_minimum_required(VERSION 3.23)
set(CMAKE_C_STANDARD 17)

project(SatelliteVisibility C)
add_executable(SatelliteVisibility "main.c" "src/input.c" "src/tle.c" "src/satellite.c")
target_include_directories(SatelliteVisibility PRIVATE "include")
