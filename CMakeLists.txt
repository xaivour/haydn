cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(haydn VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(externals EXCLUDE_FROM_ALL)
add_subdirectory(src)
