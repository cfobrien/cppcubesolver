cmake_minimum_required(VERSION 3.16.3)
project(cppcubesolver VERSION 1.0)

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/googletest)
