cmake_minimum_required(VERSION 3.10)

# set the project name
project(algorithm-visualizer VERSION 1.0)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
set(SOURCES src/main.cpp src/DataBar.cpp include/DataBar.hpp)
# add the executable
add_executable(algorithm-visualizer WIN32 ${SOURCES})
target_compile_features(algorithm-visualizer PRIVATE cxx_std_17)
target_include_directories(algorithm-visualizer PRIVATE "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(algorithm-visualizer ${CONAN_LIBS})
configure_file("assets/sorting.jpeg" "bin/assets/sorting.jpeg" COPYONLY)