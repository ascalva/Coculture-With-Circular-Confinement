cmake_minimum_required(VERSION 3.7)
project(coculture)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Cells/Cell.cpp Cells/Healthy.cpp Cells/Unhealthy.cpp Simulation.cpp)
add_executable(coculture ${SOURCE_FILES})