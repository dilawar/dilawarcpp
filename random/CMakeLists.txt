cmake_minimum_required(VERSION 3.0)
project(dilawar-random)
add_library(random INTERFACE)
target_include_directories(random INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
