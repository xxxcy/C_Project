cmake_minimum_required (VERSION 3.16)

project("C/C++")

#add_definitions(-g -no-pie)
add_compile_options(-g)
add_compile_options(-no-pie)

set(CMAKE_VERBOSE_MAKEFILEON ON)

add_subdirectory(modules)
add_subdirectory(src)