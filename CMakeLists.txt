cmake_minimum_required(VERSION 3.10)

# set the project name
project(algorithm-visualizer)
add_definitions("-std=c++17")
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
# add the executable
add_executable(algorithm-visualizer src/main.cpp)
target_link_libraries(algorithm-visualizer ${CONAN_LIBS})