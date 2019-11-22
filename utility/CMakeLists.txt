cmake_minimum_required(VERSION 3.0)
project(dilawar-utility)

add_library(utility INTERFACE)
target_include_directories(utility INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
