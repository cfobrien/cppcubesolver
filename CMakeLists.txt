cmake_minimum_required(VERSION 3.21.1)
project(cppcubesolver VERSION 1.0)

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/googletest)
