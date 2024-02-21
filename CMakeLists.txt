cmake_minimum_required(VERSION 3.9)

project(module)

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_EXTENSIONS OFF)

set(cppflow_DIR /sps/nemo/scratch/amendl/AI/falaise_module/cppflow)

find_package(Falaise REQUIRED)
# find_package(cppflow REQUIRED)

add_library(module SHARED src/lib.cpp)
# target_include_directories(module SHARED cppflow::cppflow)

target_link_libraries(module Falaise::FalaiseModule tensorflow)

