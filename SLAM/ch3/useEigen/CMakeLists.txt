cmake_minimum_required(VERSION 2.8)

project(use_eigen)

add_executable(use_eigen eigenMatrix.cpp)
include_directories("/usr/include/eigen3")
