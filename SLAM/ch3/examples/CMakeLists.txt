cmake_minimum_required(VERSION 2.8)

project(example)

add_executable(coordinate coordinateTransform.cpp)
include_directories("/usr/include/eigen3")
