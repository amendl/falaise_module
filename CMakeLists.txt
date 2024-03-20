cmake_minimum_required(VERSION 3.9)

project(module)

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_EXTENSIONS OFF)

set(cppflow_DIR /sps/nemo/scratch/amendl/AI/falaise_module/cppflow)

find_package(Falaise REQUIRED)
# find_package(cppflow REQUIRED)

include_directories(/sps/nemo/scratch/amendl/AI/falaise_module/cppflow/include)
include_directories(/sps/nemo/scratch/amendl/AI/falaise_module/TF_C_API/include)
include_directories(/sps/nemo/scratch/amendl/AI/falaise_module/src)


add_library(FirstAIModule SHARED src/lib.cpp src/common.cpp)
# target_include_directories(module SHARED cppflow::cppflow)
target_link_libraries(FirstAIModule Falaise::FalaiseModule tensorflow)

add_library(EnergyHistogramModule SHARED src/energy_histogram_module.cpp src/common.cpp)
target_link_libraries(EnergyHistogramModule Falaise::FalaiseModule tensorflow)
